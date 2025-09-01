/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:34:49 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/01 13:37:43 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_tinysort(t_node **head_a)
{
	int	a;
	int	b;
	int	c;

	if (ft_issorted(head_a))
		return ;
	a = *((*head_a)->value);
	b = *((*head_a)->next->value);
	c = *((*head_a)->next->next->value);
	if (b > c && c > a)
	{
		ft_reverse_rotate(head_a);
		ft_swap(head_a);
		ft_printf("rra\nsa\n");
	}
	else if (a > b && c > a)
	{
		ft_swap(head_a);
		ft_printf("sa\n");
	}
	else if (b > a && a > c)
	{
		ft_reverse_rotate(head_a);
		ft_printf("rra\n");
	}
	else if (a > c && c > b)
	{
		ft_rotate(head_a);
		ft_printf("ra\n");
	}
	else
	{
		ft_swap(head_a);
		ft_reverse_rotate(head_a);
		ft_printf("sa\nrra\n");
	}
}
