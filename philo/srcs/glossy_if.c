/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossy_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:35:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/08 17:08:18 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	did_someone_die(void)
{
	bool	someone_died;

	pthread_mutex_lock(&r()->death);
	if (r()->someone_died == true)
		someone_died = true;
	else
		someone_died = false;
	pthread_mutex_unlock(&r()->death);
	return (someone_died);
}

bool	did_philo_n_die(int i)
{
	pthread_mutex_lock(&r()->time);
	pthread_mutex_lock(&r()->meals);
	if (r()->time_to_die < (get_time_ms() - r()->philo[i].last_meal.millisecs))
	{
		pthread_mutex_unlock(&r()->meals);
		pthread_mutex_unlock(&r()->time);
		if (did_philo_n_eat_enough(i))
			return (false);
		return (true);
	}
	pthread_mutex_unlock(&r()->meals);
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

bool	all_philo_ate(void)
{
	if (r()->nb_of_time_each_philo_must_eat == -1)
		return (false);
	if (is_all_ate_true())
		return (true);
	else
		return (false);
}
