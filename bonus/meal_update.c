/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:20 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/31 21:38:00 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	meal_update(t_philo *philo)
{
	sem_wait(r()->meals);
	philo->nb_of_meals++;
	sem_post(r()->meals);
}
