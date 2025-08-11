/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:03:47 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/11 09:09:40 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_alpha(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			return (-1);
		else
			str++;
	}
	return (0);
}
