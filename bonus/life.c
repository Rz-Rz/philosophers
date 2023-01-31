/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:26:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 15:42:46 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

/* bool	check_death(t_philo *philo) */
/* { */
/* 	t_time			current_time; */
/* 	long			elapsed; */

/* 	now(&current_time); */
/* 	elapsed = elapsed_time(&philo->last_meal, &current_time, MILLISEC); */
/* 	if (elapsed >= r()->time_to_die) */
/* 	{ */
/* 		log_msg(philo, "died"); */
/* 		philo->check_vitals = false; */
/* 		sem_wait(r()->death); */
/* 		r()->someone_died = true; */
/* 		sem_wait(r()->death); */
/* 		return (true); */
/* 	} */
/* 	else if (did_someone_die()) */
/* 		return (true); */
/* 	return (false); */
/* } */

static void	eat(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		sem_wait(r()->forks);
		log_msg(philo, "has taken a fork");
		sem_wait(r()->forks);
		log_msg(philo, "has taken a fork");
		log_msg(philo, "is eating");
		get_time(&philo->last_meal);
		mod_sleep(r()->time_to_eat, MILLISEC, philo);
		sem_post(r()->forks);
		sem_post(r()->forks);
	}
	else
	{
		usleep(CLOCK_TICK);
		sem_wait(r()->forks);
		log_msg(philo, "has taken a fork");
		sem_wait(r()->forks);
		log_msg(philo, "has taken a fork");
		log_msg(philo, "is eating");
		get_time(&philo->last_meal);
		mod_sleep(r()->time_to_eat, MILLISEC, philo);
		sem_post(r()->forks);
		sem_post(r()->forks);
	}
}

static void	sleeep(t_philo *philo)
{
	log_msg(philo, "is sleeping");
	mod_sleep(r()->time_to_sleep, MILLISEC, philo);
}

static void	think(t_philo *philo)
{
	log_msg(philo, "is thinking");
}

int	routine(t_philo *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (r()->philo_nb == 1 && one_philo(philo))
		return (0);
	while (philo->check_vitals)
	{
		think(philo);
		eat(philo);
		sleeep(philo);
	}
	if (!philo->check_vitals)
		return (1);
	return (0);
}
