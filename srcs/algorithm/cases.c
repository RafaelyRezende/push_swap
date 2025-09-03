/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:34:49 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 17:57:51 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_case_1(t_node **head_a)
{
	ft_reverse_rotate(head_a);
	ft_swap(head_a);
	ft_printf("rra\nsa\n");
}

void	ft_case_2(t_node **head_a)
{
	ft_swap(head_a);
	ft_printf("sa\n");
}

void	ft_case_3(t_node **head_a)
{
	ft_reverse_rotate(head_a);
	ft_printf("rra\n");
}

void	ft_case_4(t_node **head_a)
{
	ft_rotate(head_a);
	ft_printf("rra\n");
}

void	ft_case_5(t_node **head_a)
{
	ft_swap(head_a);
	ft_reverse_rotate(head_a);
	ft_printf("sa\nrra\n");
}
