/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:46 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/20 17:22:38 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	init_mutex(void)
{
	int	i;

	i = 0;
	allocate_forks();
	while (i < r()->philo_nb)
	{
		if (mutex_cd(&r()->forks[i], CREATE) == false)
			return (false);
		i++;
	}
	if (mutex_cd(&r()->print, CREATE) == false)
		return (false);
	if (mutex_cd(&r()->death, CREATE) == false)
		return (false);
	return (true);
}

bool	mutex_cd(pthread_mutex_t *mutex, t_mutex_action options)
{
	int result;

	if (options == CREATE)
	{
		result = pthread_mutex_init(mutex, NULL);
		if (result < 0)
		{
			generic_err("mutex init failed");
			return (false);
		}
		return (true);
	}
	else if (options == DESTROY)
	{
		result = pthread_mutex_destroy(mutex);
		if (result < 0)
		{
			generic_err("mutex destroy failed");
			return (false);
		}
		return (true);
	}
	return (false);
}
bool	mutex_ul(pthread_mutex_t *mutex, t_mutex_action options)
{
	int result;

	if (options == LOCK)
	{
		result = pthread_mutex_lock(mutex);
		if (result < 0)
		{
			generic_err("mutex lock failed");
			return (false);
		}
		return (true);
	}
	else if (options == UNLOCK)
	{
		result = pthread_mutex_unlock(mutex);
		if (result < 0)
		{
			generic_err("mutex unlock failed");
			return (false);
		}
		return (true);
	}
	return (false);
}
