/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/15 12:14:16 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_philo					philo;
	const static t_philo 	emptyphilo;
	int						i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (generic_err("Wrong number of arguments !"));
	if (init_philo(&philo, ac, av) == -1)
		return (generic_err("Wrong arguments !"));
	if (init_mutex(&philo) == -1)
		return (generic_err("Mutex init failed !"));

	if (init_thread(&philo) == -1)
		return (generic_err("Thread init failed !"));

	while (i < philo.nb_philo)
		pthread_join(philo->thread[i++], NULL);

	ft_free(philo);
	return (0);
}

int	ft_error(char *str)
{
	printf("%s\n ", str);
	return (-1);
}



