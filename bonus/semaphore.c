/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:19:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/28 12:20:13 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/philosophers_bonus.h"

bool    init_semaphore(void)
{
        int     i;

        i = 0;
        if (sem_unlink("/forks") == -1)
                return (false);
        if (sem_unlink("/meals") == -1)
                return (false);
        if (sem_unlink("/death") == -1)
                return (false);
        if (sem_unlink("/print") == -1)
                return (false);
        if (sem_unlink("/someone_died") == -1)
                return (false);
        if (sem_unlink("/all_ate") == -1)
                return (false);
        r()->forks = sem_open("/forks", O_CREAT, 0644, r()->philo_nb);
        if (r()->forks == SEM_FAILED)
                return (false);
        if ((r()->meals = sem_open("/meals", O_CREAT, 0644, 1)) == SEM_FAILED)
                return (false);
        if ((r()->death = sem_open("/death", O_CREAT, 0644, 1)) == SEM_FAILED)
                return (false);
        if ((r()->print = sem_open("/print", O_CREAT, 0644, 1)) == SEM_FAILED)
                return (false);
        if ((r()->someone_died = sem_open("/someone_died", O_CREAT, 0644, 1)) == SEM_FAILED)
                return (false);
        if ((r()->all_ate = sem_open("/all_ate", O_CREAT, 0644, 1)) == SEM_FAILED)
                return (false);
        return (true);
}
