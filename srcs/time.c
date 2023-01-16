/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:59:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/16 18:06:20 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	get_time(t_time *time)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		generic_err("gettimeofday");
		return ;
	}
	time->millisecs = (tv.tv_sec * MILLISECONDS_IN_A_SECOND) \
			+ (tv.tv_usec / MICROSECONDS_IN_A_MILLISECOND);
	time->microsecs = (tv.tv_sec * MICROSECONDS_IN_A_SECOND) + tv.tv_usec;
}

void	now(t_time *time)
{
	get_time(time);
}

long	elapsed_time(t_time *start, t_time *current, t_time_mode mode)
{
	long	elapsed;

	if (mode == MILLISEC)
	{
		elapsed = current->millisecs - start->millisecs;
		return (elapsed);
	}
	else if (mode == MICROSEC)
	{
		elapsed = current->microsecs - start->microsecs;
		return (elapsed);
	}
	return (-1);
}

void	mod_sleep(long time_to_sleep, t_time_mode mode)
{
	int	result;

	if (mode == MILLISEC)
	{
		result = usleep(time_to_sleep * MICROSECONDS_IN_A_MILLISECOND);
		if (result == -1)
			generic_err("usleep");
	}
	else if (mode == MICROSEC)
	{
		result = usleep(time_to_sleep);
		if (result == -1)
			generic_err("usleep");
	}
}
