/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:40 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/19 18:50:36 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	init_threads(void)
{
	t_philo	*philo;
	int i;

	i = 0;
	while (i < r()->philo_nb)
	{
		if (threads_cd(r()->philo[i].id, routine, r()->philo[i], INIT) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	threads_cd(pthread_t *thread, void *(*routine)(void *), void* arg, t_thread_action options)
{
	int result;

	if (options == INIT)
	{
		result = pthread_create(thread, NULL, (*routine), arg);
		if (result < 0)
		{
			generic_err("thread create failed");
			return (false);
		}
		return (true);
	}
	else if (options == JOIN)
	{
		result = pthread_join(*thread, NULL);
		if (result < 0)
		{
			generic_err("thread destroy failed");
			return (false);
		}
		return (true);
	}
	return (false);
}
