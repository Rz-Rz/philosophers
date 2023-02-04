/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:20 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/04 08:32:37 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	meal_update(t_philo *philo)
{
	pthread_mutex_lock(&r()->meals);
	philo->nb_of_meals++;
	pthread_mutex_unlock(&r()->meals);
}

long	get_time_micro(void)
{
	t_time	time;

	get_time(&time);
	return (time.microsecs);
}
