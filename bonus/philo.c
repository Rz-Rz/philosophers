/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:19 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 08:54:30 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

sem_t room;
sem_t forks[5];

int main()
{
	int i;
	int a;
	pthread_t	philo[5];

	sem_init(&room, 0, 4);
	while (i < 5)
	{
		sem_init(&forks[i], 0, 1);
		i++;
	}
}
