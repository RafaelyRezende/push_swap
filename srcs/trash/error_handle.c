/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:03:47 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/13 18:03:10 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparser.h"

void	ft_exit_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_exit_clean(char **split, long *arr_nums)
{
	if (arr_nums)
		free(arr_nums);
	if (split)
		ft_exit_split(split);
}
