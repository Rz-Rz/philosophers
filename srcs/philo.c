/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/18 17:24:41 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_rules					rules;
	const static t_rules 	emptyrules;
	int						i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (generic_err("Wrong number of arguments !"));



	ft_free(philo);
	return (0);
}

bool init_all(t_rules *rules, int ac, char **av)
{
	if (init_rules(rules, ac, av) == -1)
		return (generic_err("Wrong arguments !"));

	if (init_mutex(rules) == -1)
		return (generic_err("Mutex init failed !"));

	if (init_philo(rules) == -1)
		return (generic_err("Philo init failed !"));

	if (init_thread(rules) == -1)
		return (generic_err("Thread init failed !"));
}
