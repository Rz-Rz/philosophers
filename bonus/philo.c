/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:44:19 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/14 15:23:20 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

sem_t room;
sem_t forks[5];

int main()
{
	int i;
	t_philo philo;
	int a[5];
	/* pthread_t	philo[5]; */

	sem_init(&room, 0, 4);
	i = -1;
	while (++i < 5)
		sem_init(&forks[i], 0, 1);
	i = -1;
	/* while (++i < 5) */
	/* { */
	/* 	a[i] = i; */
	/* 	pthread_create(&philo[i], NULL, philo_life, (void *)&a[i]); */
	/* } */
	while (++i < 5)
	{
		fork();

	}


	i = -1;
	while (++i < 5)
		pthread_join(philo[i], NULL);
}

/* void eat(t_philo philo) */
/* { */
/* 	sem_wait(&room); */
/* 	sem_wait(&forks[philo->i]); */
/* 	sem_wait(&forks[(philo->i + 1) % 5]); */
/* 	printf("philo %d is eating with forks %d and %d \n", i, i, (i + 1) % 5); */
/* 	sleep(tteat); */
/* 	sem_post(&forks[i]); */
/* 	sem_post(&forks[(i + 1) % 5]); */
/* 	sem_post(&room); */
/* } */

/* void sleep(int i) */
/* { */
/* 	printf("philo %d is sleeping \n", i); */
/* 	sleep(ttsleep); */
/* } */

/* void think(int i) */
/* { */
/* 	printf("philo %d is thinking \n", i); */
/* 	sleep(ttthink); */
/* } */

void *philo_life(void *arg)
{
	int i;

	i = *(int *)arg;
	sem_wait(&forks[i]);
	sem_wait(&forks[(i + 1) % 5]);
	printf("Philosopher %d has taken the fork %d and the fork %d\n", i, i, (i + 1) % 5);
	printf("Philosopher %d is eating\n", i);
	sleep(1);
	sem_post(&forks[i]);
	sem_post(&forks[i + 1]);
	printf("Philosopher %d is sleeping\n", i);
	sleep(1);
	printf("Philosopher %d is thinking\n", i);
	sleep(1);
	/* while (1) */
	/* { */
	/* 	eat(i); */
	/* 	sleep(i); */
	/* 	think(i); */
	/* } */
	return (NULL);
}
