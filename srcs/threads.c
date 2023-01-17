/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:34:40 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/17 17:58:07 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool init_threads(t_rules *rules)
{
	int i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if (threads_cd(&rules->threads[i], routine, ))
		if (pthread_create(&rules->threads[i], NULL, &routine, &rules->philos[i]))
			return (-1);
		i++;
	}
	return (0);
}

bool	threads_cd(pthread_t *thread, void *(*routine)(void *),  t_thread_action options)
{
	int result;

	if (options == INIT)
	{
		result = pthread_create(thread, NULL, (*routine), NULL);
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
