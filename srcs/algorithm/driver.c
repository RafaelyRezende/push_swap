/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:35:59 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/02 17:35:32 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static
void	ft_same_time_ops(t_env *this, t_cost *cost)
{
	while (cost->ra > 0 && cost->rb > 0)
	{
		ft_rotate_both(this);
		ft_printf("rr\n");
		cost->ra--;
		cost->rb--;
	}
	while (cost->rra > 0 && cost->rrb > 0)
	{
		ft_reverserotate_both(this);
		ft_printf("rrr\n");
		cost->rra--;
		cost->rrb--;
	}
}

static
void	ft_individual_ops(t_env *this, t_cost *cost)
{
	while (cost->ra > 0)
	{
		ft_rotate(&this->pile->head_a);
		ft_printf("ra\n");
		cost->ra--;
	}
	while (cost->rb > 0)
	{
		ft_rotate(&this->pile->head_b);
		ft_printf("rb\n");
		cost->rb--;
	}
	while (cost->rra > 0)
	{
		ft_reverse_rotate(&this->pile->head_a);
		ft_printf("rra\n");
		cost->rra--;
	}
	while (cost->rrb > 0)
	{
		ft_reverse_rotate(&this->pile->head_b);
		ft_printf("rrb\n");
		cost->rrb--;
	}
}

void	ft_execute_moves2b(t_env *this, int idx)
{
	t_cost	cost;

	if (!this || !this->pile || !this->pile->head_a)
		return ;
	cost = ft_calculate_cost2b(this->pile, idx);
	ft_same_time_ops(this, &cost);
	ft_individual_ops(this, &cost);
	ft_push(&this->pile->head_a, &this->pile->head_b);
	ft_printf("pb\n");
	this->pile->size_a--;
	this->pile->size_b++;
}

void	ft_execute_moves2a(t_env *this, int idx)
{
	t_cost	cost;

	if (!this || !this->pile || !this->pile->head_b)
		return ;
	cost = ft_calculate_cost2a(this->pile, idx);
	ft_same_time_ops(this, &cost);
	ft_individual_ops(this, &cost);
	ft_push(&this->pile->head_b, &this->pile->head_a);
	ft_printf("pa\n");
	this->pile->size_a++;
	this->pile->size_b--;
}

void	ft_driver(t_env *this)
{
	ft_init_sort(this);
	//ft_display(this);
	ft_passthrough_a2b(this);
	//ft_display(this);
	ft_tinysort(&this->pile->head_a);
	//ft_display(this);
	ft_passthrough_b2a(this);
	//ft_display(this);
	ft_end_position(this);
	//ft_display(this);
}
