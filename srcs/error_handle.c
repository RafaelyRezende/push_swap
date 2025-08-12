/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:03:47 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/11 19:56:55 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_errmsg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

static
int	ft_error_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_error_check(char *str)
{
	char	*tmp;
	int		i;
	int		zero_flag;
	long	res;

	i = 0;
	zero_flag = 0;
	tmp = ft_strtrim(str, " \n\t\f\r\v");
	if (!tmp)
		return (ft_errmsg());
	while (tmp[i])
	{
		if (ft_error_alpha(tmp[i]))
			return (free(tmp), ft_errmsg());
		if (tmp[i] != '0')
			zero_flag = 1;
		i++;
	}
	res = ft_atol(str);
	if (res < INT_MIN || res > INT_MAX)
		return (free(tmp), ft_errmsg());
	if (zero_flag == (int)res)
		return (0);
	else
		return (free(tmp),(int)(res));
}
