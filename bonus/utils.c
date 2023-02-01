/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:36:41 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/01 17:38:49 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	sem_close_all(void)
{
	sem_close(r()->print);
	sem_close(r()->death);
	sem_close(r()->meals);
	sem_close(r()->forks);
	sem_close(r()->time);
	sem_close(r()->stop);
}

void	sem_unlink_all(void)
{
	sem_unlink("/forks");
	sem_unlink("/meals");
	sem_unlink("/death");
	sem_unlink("/print");
	sem_unlink("/time");
	sem_unlink("/stop");
}
