/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:53 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/09 19:02:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <stdatomic.h>

// Conversion arguments
typedef enum e_s
{
	MICROSEC,
	MILLISEC
}	t_time_mode;

typedef enum e_e
{
	CREATE,
	DESTROY,
	UNLOCK,
	LOCK
}	t_mutex_action;

typedef enum e_xy
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
	pthread_t		id;
	int				index;
	t_time			last_meal;
	int				nb_of_meals;
	bool			check_vitals;
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
	bool			all_ate;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	meals;
	pthread_mutex_t	time;
	pthread_mutex_t	all_ate_mutex;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_t		*philo_id;
	t_time			start_time;
	t_time			wait_time;
	int				nb_of_time_each_philo_must_eat;
	t_philo			*philo;
	bool			someone_died;
}					t_rules;

//life.c
void	*routine(void *arg);
bool	check_death(t_philo *philo);

// log.c
void	log_msg(t_philo *philo, char *msg);

// init_philo.c
bool	init_rules(char **av);
bool	init_philo(void);
void	death_checker(void);
void	finish(void);

//protected_vars.c
void	set_all_ate_true(void);
bool	is_all_ate_true(void);

// forks.c
void	allocate_forks(void);

// threads.c
bool	init_threads(void);
bool	threads_cd(pthread_t *thread, void *(*routine)(void *),
			void *arg, t_thread_action options);
void	release_threads(int i);

// meal_update.c
void	meal_update(t_philo *philo);

// mutex.c
bool	init_mutex(void);
bool	mutex_cd(pthread_mutex_t *mutex, t_mutex_action options);
bool	mutex_ul(pthread_mutex_t *mutex, t_mutex_action options);

// philosophers.c
void	allocate_philosophers(void);

// generic_err.c
bool	generic_err(char *str);

// philo.c
bool	init_all(char **av);

//singleton.c
t_rules	*r(void);

//parsing.c
bool	is_valid_int(int nb);
int		parse(char *str);
bool	assign(void *dest, int src);

// ft_atoi.c
int		ft_atoi(const char *nptr);

// silent_kill.c
void	silent_kill(int i);
void	global_death(int i);

// time.c
void	mod_sleep(long time_to_sleep);
long	elapsed_time(t_time *start, volatile t_time *current, t_time_mode mode);
void	now(volatile t_time *time);
void	get_time(volatile t_time *time);
long	get_time_ms(void);
long	get_time_micro(void);

// memory.c
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// glossy_if.c
bool	did_someone_die(void);
bool	did_philo_n_die(int i);
bool	did_philo_n_eat_enough(int i);
bool	all_philo_ate(void);

// handle_only_one.c
bool	one_philo(t_philo *philo);

// debugging.c
void	debug_init_rules(void);
void	debug_init_mutex(void);
void	debug_init_philo(void);
void	debug_life(t_philo *philo);
void	debug_init_thread(void);
#endif
