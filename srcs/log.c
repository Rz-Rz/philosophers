/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:32 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/16 17:32:39 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	log_msg(t_rules *rules, t_philo *philo, char *msg)
{
	t_time	current_time;
	long	elapsed;

	now(&current_time);
	elapsed = elapsed_time(&rules->start_time, &current_time, MILLISEC);
	/* pthread_mutex_lock(rules->print); */
	printf("%ld %d %s\n", elapsed, philo->id, msg);
	/* pthread_mutex_unlock(rules->print); */
}
