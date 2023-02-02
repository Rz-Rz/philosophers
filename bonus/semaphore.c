/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:19:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/02 15:33:04 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	init_semaphore(void)
{
	t_rules	*ru;

	ru = r();
	sem_unlink_all();
	ru->stop = sem_open("/stop", O_CREAT, 0644, 1);
	if (ru->stop == (sem_t *)0)
		return (false);
	ru->time = sem_open("/time", O_CREAT, 0644, 1);
	if (ru->time == SEM_FAILED)
		return (false);
	ru->forks = sem_open("/forks", O_CREAT, 0644, ru->philo_nb);
	if (ru->forks == SEM_FAILED)
		return (false);
	ru->meals = sem_open("/meals", O_CREAT, 0644, 1);
	if (ru->meals == SEM_FAILED)
		return (false);
	ru->death = sem_open("/death", O_CREAT, 0644, 1);
	if (ru->death == SEM_FAILED)
		return (false);
	ru->print = sem_open("/print", O_CREAT, 0644, 1);
	if (ru->print == SEM_FAILED)
		return (false);
	return (true);
}
