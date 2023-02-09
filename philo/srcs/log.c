/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:32 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/09 16:30:19 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	log_msg(t_philo *philo, char *msg)
{
	volatile t_time			current_time;
	long			elapsed;

	now(&current_time);
	elapsed = elapsed_time(&r()->start_time, &current_time, MILLISEC);
	pthread_mutex_lock(&r()->print);
	if (did_someone_die() == false)
		printf("%ld %d %s\n", elapsed, philo->index, msg);
	pthread_mutex_unlock(&r()->print);
}
