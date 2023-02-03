/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:20 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/02 12:38:37 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	meal_update(t_philo *philo)
{
	pthread_mutex_lock(&r()->meals);
	philo->nb_of_meals++;
	if (r()->nb_of_time_each_philo_must_eat \
			!= -1 && philo->nb_of_meals == \
			r()->nb_of_time_each_philo_must_eat)
	{
		pthread_mutex_unlock(&r()->meals);
		return (true);
	}
	pthread_mutex_unlock(&r()->meals);
	return (false);
}

long	get_time_micro(void)
{
	t_time	time;

	get_time(&time);
	return (time.microsecs);
}
