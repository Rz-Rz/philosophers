/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:29:29 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/03 16:02:39 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

// name: is_valid_int
// description: check if the int is within acceptable range
// param: int
// return: 1 if valid, 0 if not
bool	is_valid_int(int nb)
{
	if (nb < 1 || nb > INT_MAX)
		return (false);
	return (true);
}

int	parse(char *str)
{
	int	n;

	n = ft_atoi(str);
	if (!is_valid_int(n))
	{
		generic_err("Invalid argument");
		return (-1);
	}
	return (n);
}

bool	assign(void *dest, int src)
{
	*(int *)dest = src;
	if (src == -1)
		return (false);
	return (true);
}
