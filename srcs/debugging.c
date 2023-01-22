/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:24:25 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/22 16:15:14 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	debug_init_rules(void)
{
	printf("philo_nb: %d\n", r()->philo_nb);
	printf("time_to_die: %d\n", r()->time_to_die);
	printf("time_to_eat: %d\n", r()->time_to_eat);
	printf("time_to_sleep: %d\n", r()->time_to_sleep);
	if (r()->nb_of_time_each_philo_must_eat)
		printf("nb_of_time_each_philo_must_eat: %d\n", r()->nb_of_time_each_philo_must_eat);
}

void	debug_init_mutex(void)
{
	int	i;

	i = 0;
	while (i < r()->philo_nb)
	{
		printf("forks[%d]: %d\n", i, pthread_mutex_trylock(&r()->forks[i]));
		printf("forks[%d]: %d\n", i, pthread_mutex_unlock(&r()->forks[i]));
		i++;
	}
	printf("print: %d\n", pthread_mutex_trylock(&r()->print));
	printf("print: %d\n", pthread_mutex_unlock(&r()->print));
	printf("death: %d\n", pthread_mutex_trylock(&r()->death));
	printf("print: %d\n", pthread_mutex_unlock(&r()->death));
}

void	debug_init_philo(void)
{
	int	i;

	i = 0;
	while (i < r()->philo_nb)
	{
		printf("philo[%d].id: %d\n", i, r()->philo[i].index);
		printf("philo[%d].nb_of_meals: %d\n", i, r()->philo[i].nb_of_meals);
		printf("philo[%d].left_fork:(expected 0)  %d\n", i, pthread_mutex_trylock(r()->philo[i].left_fork));
		printf("philo[%d].left_fork:(expected 0)  %d\n", i, pthread_mutex_unlock(r()->philo[i].left_fork));
		printf("philo[%d].right_fork:(expected 0) %d\n", i, pthread_mutex_trylock(r()->philo[i].right_fork));
		printf("philo[%d].right_fork:(expected 0) %d\n", i, pthread_mutex_unlock(r()->philo[i].right_fork));
		printf("philo[%d].ttd: %lu\n", i, r()->philo[i].ttd);
		printf("philo[%d].check_vitals: %d\n", i, r()->philo[i].check_vitals);
		printf("\n\t\t--------------------------\n");
		i++;
	}
	printf("start_time: millisec %lu\n", r()->start_time.millisecs);
	printf("start_time: microsec %lu\n", r()->start_time.microsecs);
	printf("(bool)all_ate %d\n", r()->all_ate);
}

void	debug_init_thread(void)
{
	int	i;

	i = 0;
	while (i < r()->philo_nb)
	{
		if (pthread_join(r()->philo[i].id, NULL) == 0)
			printf("philo[%d] joined\n", i);
		else
			printf("philo[%d] not joined\n", i);
		i++;
	}
}

void	debug_life(t_philo *philo)
{
	printf("philo %d is alive\n", philo->index);
	printf("nb_of_meals %d \n", philo->nb_of_meals);
}
