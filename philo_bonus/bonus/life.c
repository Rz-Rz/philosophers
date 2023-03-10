/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:26:28 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/12 13:12:32 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include <pthread.h>

void	*monitoring(void *arg)
{
	t_time			current_time;
	long			elapsed;
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		now(&current_time);
		sem_wait(r()->time);
		elapsed = elapsed_time(&philo->last_meal, &current_time, MILLISEC);
		sem_post(r()->time);
		if (elapsed >= r()->time_to_die && !did_philo_eat_enough(philo))
		{
			log_msg(philo, "died");
			sem_wait(r()->death);
			sem_wait(r()->stop);
			philo->check_vitals = false;
			sem_post(r()->death);
			return (NULL);
		}
		if (did_philo_eat_enough(philo))
			return (NULL);
		usleep(900);
	}
	return (NULL);
}

static void	eat(t_philo *philo)
{
	sem_wait(r()->forks);
	log_msg(philo, "has taken a fork");
	sem_wait(r()->forks);
	log_msg(philo, "has taken a fork");
	log_msg(philo, "is eating");
	get_eat_time(philo);
	mod_sleep(r()->time_to_eat);
	sem_post(r()->forks);
	sem_post(r()->forks);
}

static void	sleeep(t_philo *philo)
{
	log_msg(philo, "is sleeping");
	mod_sleep(r()->time_to_sleep);
}

static void	think(t_philo *philo)
{
	log_msg(philo, "is thinking");
	if (r()->philo_nb % 2 != 0)
		usleep((r()->time_to_eat) * 1000);
}

int	routine(t_philo *arg)
{
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo *)arg;
	if (r()->philo_nb == 1 && one_philo(philo))
		exit(0);
	while (r()->stop->__align == 0)
		usleep(50);
	get_time(&philo->last_meal);
	if (philo->index % 2 != 0)
		usleep(10000);
	pthread_create(&monitor, NULL, monitoring, arg);
	while (!someone_died() && !did_philo_eat_enough(philo))
	{
		eat(philo);
		meal_update(philo);
		sleeep(philo);
		think(philo);
	}
	pthread_join(monitor, NULL);
	free(r()->philo);
	if (!philo->check_vitals)
		exit(-1);
	exit(0);
}
