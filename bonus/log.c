/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:32 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 15:36:34 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	log_msg(t_philo *philo, char *msg)
{
	t_time			current_time;
	long			elapsed;

	now(&current_time);
	elapsed = elapsed_time(&r()->start_time, &current_time, MILLISEC);
	sem_wait(r()->print);
	if (did_someone_die() == false)
		printf("%ld %d %s\n", elapsed, philo->index, msg);
	sem_post(r()->print);
}
