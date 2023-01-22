/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/22 19:15:03 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (generic_err("Wrong number of arguments !"));
	if (init_all(av) == false)
		return (1);
	return (0);
}

bool	init_all(char **av)
{
	if (init_rules(av) == false)
		return (generic_err("Wrong arguments !"));
	if (init_mutex() == false)
		return (generic_err("Mutex init failed !"));
	if (init_philo() == false)
		return (generic_err("Philo init failed !"));
	if (init_threads() == false)
		return (generic_err("Thread init failed !"));
	death_checker();
	finish();
	return (true);
}

void	death_checker(void)
{
	int	i;
	int	j;

	while (!r()->all_ate)
	{
		i = 0;
		j = 0;
		while (i < r()->philo_nb)
		{
			if (r()->philo[i].nb_of_meals \
					== r()->nb_of_time_each_philo_must_eat)
				j++;
			i++;
		}
		if (j == r()->philo_nb)
			r()->all_ate = true;
		i = 0;
		while (i < r()->philo_nb)
		{
			if (r()->philo[i].check_vitals == false)
				return ;
			i++;
		}
	}
}

void	finish(void)
{
	int	i;

	i = 0;
	while (i < r()->philo_nb)
	{
		pthread_join(r()->philo[i].id, NULL);
		i++;
	}
	i = 0;
	while (i < r()->philo_nb)
	{
		pthread_mutex_destroy(&r()->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&r()->print);
	pthread_mutex_destroy(&r()->death);
	free(r()->forks);
	free(r()->philo);
}
