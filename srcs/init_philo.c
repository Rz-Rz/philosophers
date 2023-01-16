/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:07:47 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/15 16:45:06 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_philo(t_philo *philo, int ac, char **av)
{
	philo->philo_nb = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_of_time_each_philo_must_eat = ft_atoi(av[5]);
	else
		philo->nb_of_time_each_philo_must_eat = -1;
	if (philo->philo_nb < 2 || philo->philo_nb > 200 || philo->time_to_die < 60
		|| philo->time_to_eat < 60 || philo->time_to_sleep < 60
		|| philo->nb_of_time_each_philo_must_eat == 0)
		return (-1);
	return (0);
}
