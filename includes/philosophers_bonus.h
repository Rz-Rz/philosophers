/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:43:30 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 15:19:27 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


typedef struct philo_life
{
	int i;
	int tteat;
	int ttsleep;
	int ttdie;
	int ttnb;
	int philo_id[5];
}	t_philo;



void *philo_life(void *arg);


#endif
