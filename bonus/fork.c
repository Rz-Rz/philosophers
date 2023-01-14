/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:23:46 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 15:25:00 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	fork_pid(t_philo *philo, int *pid, char *error_string)
{
	*pid = fork();
	if (*pid == -1)
		generic_err(philo, error_string, 1, EXIT_FAILURE);
}
			
