/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:23:32 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/11 09:54:05 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	ft_argsize(char **av)
{
	int	count;

	count = 0;
	while (av[count])
		count++;
	return (count);
}

int	*ft_parser(char **av, int *size_numbers)
{
	int	*buf;
	int	i;

	av++;
	*size_numbers = ft_argsize(av);
	buf = (int *)calloc(*size_numbers, sizeof(int));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < *size_numbers)
	{
		if (ft_error_alpha(av[i]))
			return (free(buf), NULL);
		buf[i] = ft_atoi(av[i]);
		i++;
	}
	return (buf);
}
