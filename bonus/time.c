/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:59:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 18:15:22 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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

long	get_time_ms(void)
{
	t_time	time;

	get_time(&time);
	return (time.millisecs);
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

void	mod_sleep(long time_to_sleep)
{
	t_time	current_time;
	t_time	start;

	now(&start);
	while (true)
	{
		if (someone_died())
			break ;
		if (usleep(CLOCK_TICK) != 0)
			generic_err("usleep");
		now(&current_time);
		if ((current_time.millisecs - start.millisecs) >= time_to_sleep)
			break ;
	}
}
