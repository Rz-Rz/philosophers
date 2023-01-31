/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:21:03 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 20:10:26 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	allocate_philosophers(void)
{
	t_philo	*philosophers;

	philosophers = ft_calloc(sizeof(t_philo), r()->philo_nb);
	r()->philo = philosophers;
}
