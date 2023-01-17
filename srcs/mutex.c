/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:46 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/17 17:50:07 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(rules->print, NULL))
		return (false);
	if (pthread_mutex_init(rules->dead, NULL))
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
