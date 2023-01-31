/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:34:17 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 13:34:47 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

bool	launch_forks(void)
{
	int	i;

	i = 0;
	while (i < r()->philo_nb)
	{
		if (fork_pid(r()->philo[i].pid) == false)
			return (false);
		if (r()->philo[i].pid == 0)
			routine(&r()->philo[i]);
		i++;
	}
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
