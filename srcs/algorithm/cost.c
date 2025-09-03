/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:55:46 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:01:03 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_calculate_rotation_cost(int stack_size, \
int target_position, int *rotate, int *reverse_rotate)
{
	if (stack_size < 2)
	{
		*rotate = 0;
		*reverse_rotate = 0;
		return ;
	}
	if (target_position <= stack_size - target_position)
	{
		*rotate = target_position;
		*reverse_rotate = 0;
	}
	else
	{
		*rotate = 0;
		*reverse_rotate = stack_size - target_position;
	}
}

t_cost	ft_calculate_cost2b(t_piles *piles, int index_a)
{
	t_cost	cost;
	int		value;
	int		target;

	ft_init_cost(&cost, "b");
	value = ft_get_value_by_index(piles->head_a, index_a);
	target = ft_find_target_position_b(piles->head_b, value);
	ft_calculate_rotation_cost(piles->size_a, index_a, &cost.ra, &cost.rra);
	ft_calculate_rotation_cost(piles->size_b, target, &cost.rb, &cost.rrb);
	ft_get_total_cost(&cost);
	return (cost);
}

t_cost	ft_calculate_cost2a(t_piles *piles, int index_b)
{
	t_cost	cost;
	int		value;
	int		target;

	ft_init_cost(&cost, "a");
	value = ft_get_value_by_index(piles->head_b, index_b);
	target = ft_find_target_position_a(piles->head_a, value);
	ft_calculate_rotation_cost(piles->size_b, index_b, &cost.rb, &cost.rrb);
	ft_calculate_rotation_cost(piles->size_a, target, &cost.ra, &cost.rra);
	ft_get_total_cost(&cost);
	return (cost);
}

void	ft_get_total_cost(t_cost *cost)
{
	if (cost->ra < cost->rb)
		cost->rr = cost->ra;
	else
		cost->rr = cost->rb;
	if (cost->rra < cost->rrb)
		cost->rrr = cost->rra;
	else
		cost->rrr = cost->rrb;
	cost->total = cost->rr + cost->rrr + \
(cost->ra - cost->rr) + (cost->rb - cost->rr) + \
(cost->rra - cost->rrr) + (cost->rrb - cost->rrr) + \
cost->pb + cost->pa;
}

int	ft_get_value_by_index(t_node *head, int idx)
{
	int		i;
	t_node	*current;

	if (!head || idx < 0)
		return (0);
	i = 0;
	current = head;
	while (current && idx > i)
	{
		current = current->next;
		i++;
	}
	if (current && i == idx)
		return (*(current->value));
	return (0);
}
