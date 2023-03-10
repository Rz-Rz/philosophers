/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:03:48 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/09 12:46:49 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	set_all_ate_true(void)
{
	pthread_mutex_lock(&r()->all_ate_mutex);
	r()->all_ate = true;
	pthread_mutex_unlock(&r()->all_ate_mutex);
}

bool	is_all_ate_true(void)
{
	bool	ret;

	pthread_mutex_lock(&r()->all_ate_mutex);
	ret = r()->all_ate;
	pthread_mutex_unlock(&r()->all_ate_mutex);
	return (ret);
}
