/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:26:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/04 08:33:38 by kdhrif           ###   ########.fr       */
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
		meal_update(philo);
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
		meal_update(philo);
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
	if (r()->philo_nb == 1 && one_philo(philo))
		return (NULL);
	while (get_time_micro() < r()->wait_time.microsecs)
		usleep(50);
	get_time(&philo->last_meal);
	if (philo->index % 2 != 0)
		usleep(10000);
	while (!all_philo_ate() && !did_someone_die())
	{
		eat(philo);
		sleeep(philo);
		think(philo);
	}
	return (NULL);
}