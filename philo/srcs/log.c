/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:32 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/08 18:54:16 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	log_msg(t_philo *philo, char *msg)
{
	t_time			current_time;
	long			elapsed;

	now(&current_time);
	elapsed = elapsed_time(&r()->start_time, &current_time, MILLISEC);
	pthread_mutex_lock(&r()->print);
	if (did_someone_die() == false && all_philo_ate() == false && did_philo_n_eat_enough(philo->index - 1) == false)
		printf("%ld %d %s\n", elapsed, philo->index, msg);
	pthread_mutex_unlock(&r()->print);
}
