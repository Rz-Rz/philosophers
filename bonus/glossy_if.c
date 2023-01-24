/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glossy_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:35:34 by kdhrif            #+#    #+#             */
/*   Updated: 2023/01/24 14:37:51 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	did_someone_die(void)
{
	bool	someone_died;

	pthread_mutex_lock(&r()->death);
	if (r()->someone_died == true)
		someone_died = true;
	else
		someone_died = false;
	pthread_mutex_unlock(&r()->death);
	return (someone_died);
}
