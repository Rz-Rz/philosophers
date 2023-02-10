/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:21:03 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/10 17:32:37 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	allocate_philosophers(void)
{
	t_philo	*philosophers;

	philosophers = ft_calloc(sizeof(t_philo), r()->philo_nb);
	if (!philosophers)
		return ;
	r()->philo = philosophers;
}
