/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:23:32 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/11 13:57:21 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_parser(char **av, int size)
{
	long	*tmp_val;
	int		i;

	tmp_val = (long	*)ft_calloc(size - 1, sizeof(long));
	if (!tmp_val)
		return (NULL);
	i = 0;
	while (++i < size)
	{
		if (ft_error_check(av[i]))
			return (free(tmp_val), NULL);
		tmp_val[i - 1] = ft_atol(av[i]);
	}
	return (tmp_val);
}

t_stack	*ft_initialize_stack()
{
}
