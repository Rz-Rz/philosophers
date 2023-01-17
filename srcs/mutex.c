/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:46 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/17 11:54:20 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(rules->print, NULL))
		return (-1);
	if (pthread_mutex_init(rules->dead, NULL))
		return (-1);
	return (0);
}

void	init_mutex(pthread_mutex_t mutex)
{
	int result;

	result = pthread_mutex_init(&mutex, NULL);
	if (result < 0)
	{
		generic_err("mutex init failed");
		return (EXIT_FAILURE);
	}


}
