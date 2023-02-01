/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:26:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 17:46:10 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include <pthread.h>

void	*monitoring(void *arg)
{
	t_time			current_time;
	long			elapsed;
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		now(&current_time);
		sem_wait(r()->time);
		elapsed = elapsed_time(&philo->last_meal, &current_time, MILLISEC);
		sem_post(r()->time);
		if (elapsed >= r()->time_to_die && !did_philo_eat_enough(philo))
		{
			log_msg(philo, "died");
			sem_wait(r()->death);
			sem_wait(r()->stop);
			philo->check_vitals = false;
			sem_post(r()->death);
			return (NULL);
		}
		if (did_philo_eat_enough(philo))
			return (NULL);
		usleep(CLOCK_TICK);
	}
	return (NULL);
}

static void	eat(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		sem_wait(r()->forks);
		log_msg(philo, "has taken a fork");
		sem_wait(r()->forks);
		log_msg(philo, "has taken a fork");
		log_msg(philo, "is eating");
		sem_wait(r()->time);
		get_time(&philo->last_meal);
		sem_post(r()->time);
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
		sem_wait(r()->time);
		get_time(&philo->last_meal);
		sem_post(r()->time);
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
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo *)arg;
	if (r()->philo_nb == 1 && one_philo(philo))
		exit(0);
	pthread_create(&monitor, NULL, monitoring, arg);
	while (is_alive(philo) && !did_philo_eat_enough(philo))
	{
		think(philo);
		eat(philo);
		meal_update(philo);
		sleeep(philo);
	}
	pthread_join(monitor, NULL);
	if (!philo->check_vitals)
		exit(-1);
	exit(0);
}
