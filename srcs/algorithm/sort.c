/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:34:49 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:30:27 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static
void	ft_case_1(t_node **head_a)
{
	ft_reverse_rotate(head_a);
	ft_swap(head_a);
	ft_printf("rra\nsa\n");
}

static
void	ft_case_2(t_node **head_a)
{
	ft_swap(head_a);
	ft_printf("sa\n");
}

static
void	ft_case_3(t_node **head_a)
{
	ft_reverse_rotate(head_a);
	ft_printf("rra\n");
}

static
void	ft_case_4(t_node **head_a)
{
	ft_rotate(head_a);
	ft_printf("ra\n");
}

void	ft_tinysort(t_node **head_a)
{
	int	a;
	int	b;
	int	c;

	if (ft_issorted(head_a) || !(*head_a)->next || !(*head_a)->next->next)
		return ;
	a = *((*head_a)->value);
	b = *((*head_a)->next->value);
	c = *((*head_a)->next->next->value);
	if (b > c && c > a)
		ft_case_1(head_a);
	else if (a > b && c > a)
		ft_case_2(head_a);
	else if (b > a && a > c)
		ft_case_3(head_a);
	else if (a > c && c > b)
		ft_case_4(head_a);
	else
	{
		ft_swap(head_a);
		ft_reverse_rotate(head_a);
		ft_printf("sa\nrra\n");
	}
}
