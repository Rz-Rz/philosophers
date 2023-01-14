/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 08:07:44 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (ft_error("Error: Wrong number of arguments !"));
	if (!(philo = (t_philo *)malloc(sizeof(t_philo))))
		return (ft_error("Error: Malloc failed !"));
	if (ft_init_philo(philo, ac, av) == -1)
		return (ft_error("Error: Wrong arguments !"));
	if (ft_init_mutex(philo) == -1)
		return (ft_error("Error: Mutex init failed !"));
	if (ft_init_thread(philo) == -1)
		return (ft_error("Error: Thread init failed !"));
	while (i < philo->nb_philo)
		pthread_join(philo->thread[i++], NULL);
	ft_free(philo);
	return (0);
}

int	ft_error(char *str)
{
	printf("%s\n ", str);
	return (-1);
}

int	ft_init_philo(t_philo *philo, int ac, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_must_eat = ft_atoi(av[5]);
	else
		philo->nb_must_eat = -1;
	if (philo->nb_philo < 2 || philo->nb_philo > 200 || philo->time_to_die < 60
		|| philo->time_to_eat < 60 || philo->time_to_sleep < 60
		|| philo->nb_must_eat == 0)
		return (-1);
	return (0);
}

int	ft_init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	if (!(philo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
		* philo->nb_philo)))
		return (-1);
	if (!(philo->thread = (pthread_t *)malloc(sizeof(pthread_t)
		* philo->nb_philo)))
		return (-1);
	if (!(philo->philo = (t_philo *)malloc(sizeof(t_philo) * philo->nb_philo)))
		return (-1);
	if (pthread_mutex_init(&philo->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&philo->dead, NULL) != 0)
		return (-1);
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}


