/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossy_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:35:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 14:50:31 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include <semaphore.h>

bool	did_philo_die(t_philo *philo)
{
	bool	someone_died;

	sem_wait(r()->death);
	if (philo->check_vitals == false)
		someone_died = true;
	else
		someone_died = false;
	sem_post(r()->death);
	return (someone_died);
}

bool	did_philo_eat_enough(t_philo *philo)
{
	bool	eat_enough;

	sem_wait(r()->meals);
	if (philo->nb_of_meals >= r()->nb_of_time_each_philo_must_eat && r()->nb_of_time_each_philo_must_eat != -1)
		eat_enough = true;
	else
		eat_enough = false;
	sem_post(r()->meals);
	return (eat_enough);
}

bool	is_alive(t_philo *philo)
{
	sem_wait(r()->death);
	if (philo->check_vitals == true)
	{
		sem_post(r()->death);
		return (true);
	}
	sem_post(r()->death);
	return (false);
}
