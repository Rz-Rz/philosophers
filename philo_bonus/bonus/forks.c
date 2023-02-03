/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:34:17 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/02 15:03:50 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	launch_forks(void)
{
	int		i;
	t_philo	*philo;

	i = 0;
	sem_wait(r()->stop);
	while (i < r()->philo_nb)
	{
		philo = &r()->philo[i];
		if (fork_pid(&(philo->pid)) == false)
			return (false);
		if (r()->philo[i].pid == 0)
			routine(&r()->philo[i]);
		i++;
	}
	sem_post(r()->stop);
	return (true);
}

bool	fork_pid(int *pid)
{
	*pid = fork();
	if (*pid == -1)
		return (generic_err("Fork failed !"));
	else
		return (true);
}
