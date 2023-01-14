/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:19 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 07:46:27 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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

