/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:40 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/16 18:05:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int init_threads(t_rules *rules)
{
	int i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if (pthread_create(&rules->threads[i], NULL, &routine, &rules->philos[i]))
			return (-1);
		i++;
	}
	return (0);
}
