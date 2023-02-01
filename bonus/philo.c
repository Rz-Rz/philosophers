/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 17:41:42 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include <stdlib.h>

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
		return (generic_err("Wrong arguments !"));
	if (init_semaphore() == false)
		return (generic_err("Semaphore init failed !"));
	if (init_philo() == false)
		return (generic_err("Philo init failed !"));
	if (launch_forks() == false)
		return (generic_err("Thread init failed !"));
	finish();
	return (true);
}

void	finish(void)
{
	int	i;
	int	ret;

	i = 0;
	while (i < r()->philo_nb)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = 0;
			while (i < r()->philo_nb)
			{
				kill(r()->philo[i].pid, SIGKILL);
				i++;
			}
			sem_post(r()->stop);
			break ;
		}
		i++;
	}
	sem_close_all();
	sem_unlink_all();
	free(r()->philo);
}
