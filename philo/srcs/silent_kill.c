/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_kill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:40:31 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/28 11:43:50 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	silent_kill(int i)
{
	log_msg(&r()->philo[i], "died");
	pthread_mutex_lock(&r()->death);
	r()->someone_died = true;
	r()->philo[i].check_vitals = false;
	pthread_mutex_unlock(&r()->death);
}

void	global_death(int i)
{
	if (did_philo_n_die(i))
		silent_kill(i);
}
