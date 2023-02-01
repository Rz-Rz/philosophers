/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:20:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 17:39:42 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

// semaphore.c
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <semaphore.h>

// Conversion arguments
typedef enum t
{
	MICROSEC,
	MILLISEC
}	t_time_mode;

typedef enum e
{
	CREATE,
	DESTROY,
	UNLOCK,
	LOCK
}	t_mutex_action;

typedef enum b
{
	INIT,
	JOIN
}	t_thread_action;

// types to reduce error risk
typedef long	t_millisecs;
typedef long	t_microsecs;

// time
# define MILLISECONDS_IN_A_SECOND 1000
# define MICROSECONDS_IN_A_MILLISECOND 1000
# define MICROSECONDS_IN_A_SECOND 1000000

# define CLOCK_TICK 1500

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
}	t_time;

// individual philosopher
typedef struct s_philo
{
	int				pid;
	int				index;
	t_time			last_meal;
	int				nb_of_meals;
	bool			check_vitals;
	long			ttd;
	char			*name;
}					t_philo;

typedef struct s_rules
{
	int				philo_nb;
	char			**argv;
	int				argc;
	bool			all_ate;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*death;
	sem_t			*meals;
	sem_t			*time;
	sem_t			*stop;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_time			start_time;
	int				nb_of_time_each_philo_must_eat;
	t_philo			*philo;
	bool			someone_died;
}					t_rules;

//singleton.c
t_rules	*r(void);

//semaphore.c
bool	init_semaphore(void);

//philo.c
bool	init_all(char **av);
void	finish(void);

//utils.c
void	sem_close_all(void);
void	sem_unlink_all(void);

//error.c
bool	generic_err(char *str);

//init_philo.c
bool	init_rules(char **av);
bool	init_philo(void);

//forks.c
bool	launch_forks(void);
bool	fork_pid(int *pid);

//glossy_if
bool	did_philo_eat_enough(t_philo *philo);
bool	did_philo_die(t_philo *philo);
bool	is_alive(t_philo *philo);

//meal_update.c
void	meal_update(t_philo *philo);

//handle_only_one.c
bool	one_philo(t_philo *philo);

//log.c
void	log_msg(t_philo *philo, char *msg);

//life.c
int		routine(t_philo *arg);
void	*monitoring(void *arg);

//philosophers.c
void	allocate_philosophers(void);

// time.c
void	mod_sleep(long time_to_sleep, t_time_mode mode, t_philo *philo);
long	elapsed_time(t_time *start, t_time *current, t_time_mode mode);
void	now(t_time *time);
void	get_time(t_time *time);
long	get_time_ms(void);

//parsing.c
bool	is_valid_int(int nb);
int		parse(char *str);
bool	assign(void *dest, int src);

//memory.c
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
