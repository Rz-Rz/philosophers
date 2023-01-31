/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:46:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 15:37:15 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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
		return (generic_err("Mutex init failed !"));
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
	ret = 0;
	while (i < r()->philo_nb)
	{
		waitpid(-1, &ret, 0);
		if (ret == -1)
		{
			i = 0;
			while (i < r()->philo_nb)
			{
				kill(*(r()->philo[i].pid), SIGKILL);
				i++;
			}
			break ;
		}
		i++;
	}
	sem_close(r()->print);
	sem_close(r()->death);
	sem_close(r()->meals);
	sem_close(r()->time);
	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/meals");
	sem_unlink("/time");
	free(r()->forks);
	free(r()->philo);
}
