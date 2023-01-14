/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:53 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 07:52:53 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H



#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

typedef struct t_philo
{
	int				id;
	int				nb_philo;
	int				nb_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				*fork;
	int				*eat;
	int				*die;
	int				*sleep;
	int				*end;
	int				*start;
	int				*start_eat;
	int				*start_sleep;
	int				*start_die;
	int				*start_end;
	int				*start_start;
	int				*start_start_eat;
	int				*start_start_sleep;
	int				*start_start_die;
	int				*start_start_end;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*death;
	sem_t			*end_eat;
}					t_philo;



int	ft_error(char *str);

int	ft_init_philo(t_philo *philo, int ac, char **av);

#endif
