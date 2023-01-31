/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossy_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:35:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 15:37:06 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	did_someone_die(void)
{
	bool	someone_died;

	sem_wait(r()->death);
	if (r()->someone_died == true)
		someone_died = true;
	else
		someone_died = false;
	sem_post(r()->death);
	return (someone_died);
}

/*
bool	did_philo_n_die(int i)
{
	pthread_mutex_lock(&r()->time);
	if (r()->time_to_die < (get_time_ms() - r()->philo[i].last_meal.millisecs))
	{
		pthread_mutex_unlock(&r()->time);
		if (did_philo_n_eat_enough(i))
			return (false);
		return (true);
	}
	pthread_mutex_unlock(&r()->time);
	return (false);
}

bool	did_philo_n_eat_enough(int i)
{
	if (r()->nb_of_time_each_philo_must_eat == -1)
		return (false);
	if (r()->philo[i].nb_of_meals >= r()->nb_of_time_each_philo_must_eat)
		return (true);
	return (false);
}
*/
