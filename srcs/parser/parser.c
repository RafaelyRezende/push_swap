/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:23:32 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/21 10:07:10 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	*ft_cast_arr(long *arr_nums, int size)
{
	int	*rptr;
	int	i;

	rptr = (int *)ft_calloc(size, sizeof(int));
	if (!rptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		rptr[i] = (int)arr_nums[i];
		if (ft_isdup(rptr[i], rptr, i))
			return (free(rptr), NULL);
		i++;
	}
	return (rptr);
}

long	*ft_check_overflow(char **split, int size)
{
	long	*arr_nums;
	int		i;

	arr_nums = (long *)ft_calloc(size, sizeof(long));
	if (!arr_nums)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr_nums[i] = ft_strtol(split[i]);
		if (arr_nums[i] == LONG_MAX)
			return (free(arr_nums), NULL);
		i++;
	}
	return (arr_nums);
}

int	ft_get_nums(t_env *this, const char *str)
{
	long	*arr_nums;
	char	**split;

	split = ft_split(str, ' ');
	if (!split)
		return (-1);
	this->size = ft_split_size(split);
	arr_nums = ft_check_overflow(split, this->size);
	if (!arr_nums)
		return (ft_exit_clean(split, arr_nums), -1);
	this->nums = ft_cast_arr(arr_nums, this->size);
	ft_exit_clean(split, arr_nums);
	return (0);
}
