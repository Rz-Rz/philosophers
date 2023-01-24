/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:26:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/24 15:48:47 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>

bool	check_death(t_philo *philo)
{
	t_time			current_time;
	long			elapsed;

	now(&current_time);
	elapsed = elapsed_time(&philo->last_meal, &current_time, MILLISEC);
	if (elapsed >= r()->time_to_die)
	{
		log_msg(philo, "died");
		philo->check_vitals = false;
		pthread_mutex_lock(&r()->death);
		r()->someone_died = true;
		pthread_mutex_unlock(&r()->death);
		return (true);
	}
	else if (did_someone_die())
		return (true);
	return (false);
}

static void	eat(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		log_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		log_msg(philo, "has taken a fork");
		log_msg(philo, "is eating");
		get_time(&philo->last_meal);
		mod_sleep(r()->time_to_eat, MILLISEC, philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		log_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		log_msg(philo, "has taken a fork");
		log_msg(philo, "is eating");
		get_time(&philo->last_meal);
		mod_sleep(r()->time_to_eat, MILLISEC, philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = r()->start_time;
	while (philo->check_vitals && !did_someone_die())
	{
		if (check_death(philo))
			break ;
		eat(philo);
		if (check_death(philo))
			break ;
		pthread_mutex_lock(&r()->meals);
		philo->nb_of_meals++;
		if (r()->nb_of_time_each_philo_must_eat \
				!= -1 && philo->nb_of_meals == \
				r()->nb_of_time_each_philo_must_eat)
		{
			pthread_mutex_unlock(&r()->meals);
			break ;
		}
		pthread_mutex_unlock(&r()->meals);
		sleeep(philo);
		if (check_death(philo))
			break ;
		think(philo);
		if (check_death(philo))
			break ;
	}
	return (NULL);
}
