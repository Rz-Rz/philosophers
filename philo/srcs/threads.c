/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:40 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/08 18:46:45 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	init_threads(void)
{
	int	i;

	i = -1;
	r()->wait_time.microsecs = r()->start_time.microsecs + 1000;
	while (++i < r()->philo_nb)
	{
		if (pthread_create(&r()->philo[i].id, NULL, routine, &r()->philo[i]))
		{
			release_threads(i);
			free(r()->philo);
			free(r()->forks);
			return (false);
		}
	}
	return (true);
}

void	release_threads(int i)
{
	while (--i >= 0)
		pthread_join(r()->philo[i].id, NULL);
}

bool	threads_cd(pthread_t *thread, void *(*routine)(void *),
		void *arg, t_thread_action options)
{
	int	result;

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
