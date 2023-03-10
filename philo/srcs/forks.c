/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:34:17 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/10 17:32:09 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	allocate_forks(void)
{
	pthread_mutex_t	*forks;

	forks = ft_calloc(sizeof(pthread_mutex_t), r()->philo_nb);
	if (!forks)
		return ;
	r()->forks = forks;
}
