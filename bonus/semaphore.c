/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:19:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/28 17:10:52 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool    init_semaphore(void)
{
	int     i;

	i = 0;
	if (sem_unlink("/forks") == -1)
		return (false);
	if (sem_unlink("/meals") == -1)
		return (false);
	if (sem_unlink("/death") == -1)
		return (false);
	if (sem_unlink("/print") == -1)
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
