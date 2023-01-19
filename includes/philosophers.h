/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:53 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/19 18:49:53 by kdhrif           ###   ########.fr       */
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
#include <limits.h>
#include <stdbool.h>

// Conversion arguments
typedef enum
{
	MICROSEC,
	MILLISEC
} t_time_mode;

typedef enum
{
	CREATE,
	DESTROY,
	UNLOCK,
	LOCK
} t_mutex_action;

typedef enum
{
	INIT,
	JOIN
} t_thread_action;

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

// individual philosopher
typedef struct s_philo
{
	pthread_t		id;
	t_time			last_meal;
	int				nb_of_meals;
	int				check_vitals;
	long			ttd;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

// env
typedef struct s_rules
{
	int				philo_nb;
	char			**argv;
	int				argc;
	pthread_mutex_t *forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_t		*philo_id;
	t_time			start_time;
	int				nb_of_time_each_philo_must_eat;
	t_philo			*philo;
}					t_rules;


// init_philo.c
bool	init_rules(t_rules *rules, int ac, char **av);

// forks.c
void	allocate_forks(void);

// threads.c
bool	threads_cd(pthread_t *thread, void *(*routine)(void *), void* arg, t_thread_action options);

// mutex.c
bool	init_mutex(t_rules *rules);
bool	mutex_cd(pthread_mutex_t *mutex, t_mutex_action options);
bool	mutex_ul(pthread_mutex_t *mutex, t_mutex_action options);

// philosophers.c
void	allocate_philosophers(void);

// generic_err.c
int		generic_err(char *str);

// philo.c
bool init_all(t_rules *rules, int ac, char **av);

//singleton.c
t_rules	*r(void);

//parsing.c
bool	is_valid_int(int nb);
int		parse(char *str);
bool	assign(void *dest, int src);

// ft_atoi.c
int		ft_atoi(const char *nptr);

// time.c
void	mod_sleep(long time_to_sleep, t_time_mode mode);
long	elapsed_time(t_time *start, t_time *current, t_time_mode mode);
void	now(t_time *time);
void	get_time(t_time *time);

// memory.c
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
