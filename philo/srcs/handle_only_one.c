/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_only_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:37:19 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/24 16:39:24 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	one_philo(t_philo *philo)
{
	log_msg(philo, "has taken a fork");
	mod_sleep(r()->time_to_die, MILLISEC, philo);
	check_death(philo);
	return (true);
}
