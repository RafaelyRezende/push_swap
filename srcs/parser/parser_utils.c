/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:23:32 by rluis-ya          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/14 12:56:21 by rluis-ya         ###   ########.fr       */
=======
/*   Updated: 2025/08/14 16:19:16 by rluis-ya         ###   ########.fr       */
>>>>>>> feature/stack_moves
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

long long	ft_strtol(const char *nptr)
{
	long long	nbr;
	int			sign;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (LONG_MAX);
		nbr = nbr * 10 + *nptr - '0';
		if (nbr * sign < INT_MIN || nbr * sign > INT_MAX)
			return (LONG_MAX);
		nptr++;
	}
	return (nbr * sign);
}

int	ft_isdup(int n1, int *set, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n1 == set[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
