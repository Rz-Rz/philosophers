/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:46 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/15 12:14:58 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL))
			return (-1);
		i++;
	}
	/* if (pthread_mutex_init(&philo->print, NULL)) */
	/* 	return (1); */
	/* if (pthread_mutex_init(&philo->dead, NULL)) */
	/* 	return (1); */
	return (0);
}
