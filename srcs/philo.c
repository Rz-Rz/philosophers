/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/20 13:22:09 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (generic_err("Wrong number of arguments !"));
	if (init_all(av) == false)
		return (1);
	/* free_philo(philo); */
	return (0);
}

bool init_all(char **av)
{
	if (init_rules(av) == false)
		return (generic_err("Wrong arguments !"));

	if (init_mutex() == false)
		return (generic_err("Mutex init failed !"));

	if (init_philo() == false)
		return (generic_err("Philo init failed !"));

	if (init_threads() == false)
		return (generic_err("Thread init failed !"));
	return (true);
}
