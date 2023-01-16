/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:46 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/16 17:27:46 by kdhrif           ###   ########.fr       */
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
