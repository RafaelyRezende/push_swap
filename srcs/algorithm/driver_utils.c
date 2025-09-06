/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:17:48 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:02:36 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_init_sort(t_env *this)
{
	int	counter;

	if (!this || !this->pile || !this->pile->head_a)
		return ;
	counter = 0;
	while (this->pile->size_a > 3 && counter < 2)
	{
		ft_push(&this->pile->head_a, &this->pile->head_b);
		ft_printf("pb\n");
		this->pile->size_a--;
		this->pile->size_b++;
		counter++;
	}
}

void	ft_passthrough_a2b(t_env *this)

{
	int	cheapest;

	if (!this || !this->pile || !this->pile->head_a)
		return ;
	while (this->pile->size_a > 3)
	{
		cheapest = ft_find_cheapest_to_b(this->pile);
		if (cheapest != -1)
			ft_execute_moves2b(this, cheapest);
		else
			break ;
	}
}

void	ft_passthrough_b2a(t_env *this)
{
	int	cheapest;

	if (!this || !this->pile || !this->pile->head_b)
		return ;
	while (this->pile->size_b > 0)
	{
		cheapest = ft_find_cheapest_to_a(this->pile);
		if (cheapest != -1 && this->pile->head_b)
			ft_execute_moves2a(this, cheapest);
		else
			break ;
	}
}

int	ft_min_pos(t_node *stack)
{
	t_node	*current;
	t_node	*min;
	int		min_index;
	int		current_index;

	if (!stack || !stack->next)
		return (0);
	current = stack;
	min = stack;
	min_index = 0;
	current_index = 0;
	while (current)
	{
		if (*(min->value) > *(current->value))
		{
			min = current;
			min_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (min_index);
}

void	ft_end_position(t_env *this)
{
	int	index_smallest;
	int	reverse_rotations_count;

	if (!this || !this->pile || !this->pile->head_a)
		return ;
	index_smallest = ft_min_pos(this->pile->head_a);
	if (index_smallest <= this->pile->size_a / 2)
	{
		while (index_smallest > 0)
		{
			ft_rotate(&this->pile->head_a);
			ft_printf("ra\n");
			index_smallest--;
		}
	}
	else
	{
		reverse_rotations_count = this->pile->size_a - index_smallest;
		while (reverse_rotations_count > 0)
		{
			ft_reverse_rotate(&this->pile->head_a);
			ft_printf("rra\n");
			reverse_rotations_count--;
		}
	}
}
