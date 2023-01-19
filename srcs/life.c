/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:26:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/19 21:20:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		eat(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		/* print_status(philo, "has taken a fork"); */
		pthread_mutex_lock(philo->right_fork);
		/* print_status(philo, "has taken a fork"); */
		/* print_status(philo, "is eating"); */
		philo->last_meal = get_time();
		/* ft_usleep(r()->time_to_eat); */
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		/* print_status(philo, "is sleeping"); */
		/* ft_usleep(r()->time_to_sleep); */
		/* print_status(philo, "is thinking"); */
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		/* print_status(philo, "has taken a fork"); */
		pthread_mutex_lock(philo->left_fork);
		/* print_status(philo, "has taken a fork"); */
		/* print_status(philo, "is eating"); */
		philo->last_meal = get_time();
		/* ft_usleep(r()->time_to_eat); */
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		/* print_status(philo, "is sleeping"); */
		/* ft_usleep(r()->time_to_sleep); */
		/* print_status(philo, "is thinking"); */
	}
}
