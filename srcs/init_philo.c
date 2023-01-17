/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:07:47 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/17 17:24:53 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* int	init_philo(t_philo *philo, int ac, char **av) */
/* { */
/* 	philo->philo_nb = ft_atoi(av[1]); */
/* 	philo->time_to_die = ft_atoi(av[2]); */
/* 	philo->time_to_eat = ft_atoi(av[3]); */
/* 	philo->time_to_sleep = ft_atoi(av[4]); */
/* 	if (ac == 6) */
/* 		philo->nb_of_time_each_philo_must_eat = ft_atoi(av[5]); */
/* 	else */
/* 		philo->nb_of_time_each_philo_must_eat = -1; */
/* 	if (philo->philo_nb < 2 || philo->philo_nb > 200 || philo->time_to_die < 60 */
/* 		|| philo->time_to_eat < 60 || philo->time_to_sleep < 60 */
/* 		|| philo->nb_of_time_each_philo_must_eat == 0) */
/* 		return (-1); */
/* 	return (0); */
/* } */

bool	init_philo(t_rules *rules, int ac, char **av)
{
	if (assign(&rules->philo_nb, parse(av[1])) == false)
		return (false);
	if (assign(&rules->time_to_die, parse(av[2])) == false)
		return (false);
	if (assign(&rules->time_to_eat, parse(av[3])) == false)
		return (false);
	if (assign(&rules->time_to_sleep, parse(av[4])) == false)
		return (false);
	if (av[5])
		if (assign(&rules->nb_of_time_each_philo_must_eat, parse(av[5])) == false)
			return (false);
	return (true);
}
