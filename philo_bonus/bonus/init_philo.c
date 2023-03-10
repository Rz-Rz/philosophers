/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:07:47 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/09 17:16:25 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	init_rules(char **av)
{
	if (assign(&r()->philo_nb, parse(av[1])) == false)
		return (false);
	if (assign(&r()->time_to_die, parse(av[2])) == false)
		return (false);
	if (assign(&r()->time_to_eat, parse(av[3])) == false)
		return (false);
	if (assign(&r()->time_to_sleep, parse(av[4])) == false)
		return (false);
	if (av[5])
	{
		if (assign(&r()->nb_of_time_each_philo_must_eat, parse(av[5])) == false)
			return (false);
	}
	else
		r()->nb_of_time_each_philo_must_eat = -1;
	return (true);
}

bool	init_philo(void)
{
	int	i;

	allocate_philosophers();
	i = 0;
	get_time(&r()->start_time);
	while (i < r()->philo_nb)
	{
		r()->philo[i].index = i + 1;
		r()->philo[i].ttd = r()->time_to_die;
		r()->philo[i].nb_of_meals = 0;
		r()->philo[i].check_vitals = true;
		r()->philo[i].last_meal = r()->start_time;
		i++;
	}
	r()->all_ate = false;
	r()->someone_died = false;
	return (true);
}
