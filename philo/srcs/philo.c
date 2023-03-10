/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/09 18:32:33 by kdhrif           ###   ########.fr       */
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
		return (false);
	if (init_mutex() == false)
		return (false);
	if (init_philo() == false)
		return (false);
	if (init_threads() == false)
		return (false);
	death_checker();
	finish();
	return (true);
}

void	death_checker(void)
{
	int	i;
	int	j;

	while (!r()->all_ate && !did_someone_die())
	{
		usleep(900);
		i = 0;
		j = 0;
		mutex_ul(&r()->meals, LOCK);
		while (i < r()->philo_nb)
		{
			if (did_philo_n_eat_enough(i))
				j++;
			i++;
		}
		mutex_ul(&r()->meals, UNLOCK);
		if (j == r()->philo_nb)
			set_all_ate_true();
		i = -1;
		while (++i < r()->philo_nb)
			global_death(i);
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
	pthread_mutex_destroy(&r()->meals);
	pthread_mutex_destroy(&r()->time);
	pthread_mutex_destroy(&r()->all_ate_mutex);
	free(r()->forks);
	free(r()->philo);
}
