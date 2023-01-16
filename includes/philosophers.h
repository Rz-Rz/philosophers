/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:53 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/16 17:37:55 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>

// Conversion arguments
typedef enum
{
	MICROSEC,
	MILLISEC
} t_time_mode;

// types to reduce error risk
typedef long t_millisecs;
typedef long t_microsecs;


// time
# define MILLISECONDS_IN_A_SECOND 1000
# define MICROSECONDS_IN_A_MILLISECOND 1000
# define MICROSECONDS_IN_A_SECOND 1000000

// msg
# define TOOK_FORK_MSG "has taken a fork"
# define EATING_MSG "is eating"
# define SLEEPING_MSG "is sleeping"
# define THINKING_MSG "is thinking"
# define DIED_MSG "died"


// time_struct
typedef struct s_time
{
	t_millisecs		millisecs;
	t_microsecs		microsecs;
} t_time;

// env
typedef struct s_rules
{
	int				philo_nb;
	pthread_mutex_t *forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_t		*philo_id;
	t_time			start_time;
	int				nb_of_time_each_philo_must_eat;
	int				*nb_of_time_each_philo_eat;
}					t_rules;

// individual philosopher
typedef struct s_philo
{
	pthread_t		id;
	t_rules			*rules;
	t_time			last_meal;
	int				nb_of_time_eat;
	int				check_vitals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

// init_philo.c
int	init_philo(t_rules *rules, int ac, char **av);

// mutex.c
int	init_mutex(t_rules *rules);

// generic_err.c
int generic_err(char *str);

// ft_atoi.c
int	ft_atoi(const char *nptr);

// time.c
void	mod_sleep(long time_to_sleep, t_time_mode mode);
long	elapsed_time(t_time *start, t_time *current, t_time_mode mode);
void	now(t_time *time);
void	get_time(t_time *time);

#endif
