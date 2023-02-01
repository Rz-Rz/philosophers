/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:19:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 17:32:40 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool    init_semaphore(void)
{
	sem_unlink("/forks");
	sem_unlink("/meals");
	sem_unlink("/death");
	sem_unlink("/print");
	sem_unlink("/time");
	sem_unlink("/stop");
	r()->stop = sem_open("/stop", O_CREAT, 0644, 1);
	if (r()->stop == SEM_FAILED)
		return (false);
	r()->time = sem_open("/time", O_CREAT, 0644, 1);
	if (r()->time == SEM_FAILED)
		return (false);
	r()->forks = sem_open("/forks", O_CREAT, 0644, r()->philo_nb);
	if (r()->forks == SEM_FAILED)
		return (false);
	r()->meals = sem_open("/meals", O_CREAT, 0644, 1);
	if (r()->meals == SEM_FAILED)
		return (false);
	r()->death = sem_open("/death", O_CREAT, 0644, 1);
	if (r()->death == SEM_FAILED)
		return (false);
	r()->print = sem_open("/print", O_CREAT, 0644, 1);
	if (r()->print == SEM_FAILED)
		return (false);
	return (true);
}
