/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:55:46 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/02 17:49:28 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_calculate_rotation_cost(int stack_size, int target_position, int *rotate, int *reverse_rotate)
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

void	ft_init_cost(t_cost *cost, const char *flag)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->total = 0;
	if (!ft_strcmp(flag, "a"))
	{
		cost->pa = 1;
		cost->pb = 0;
	}
	else
	{
		cost->pa = 0;
		cost->pb = 1;
	}
}

int	ft_find_cheapest_to_a(t_piles *piles)
{
	t_cost	current_cost;
	int		idx_minimum;
	int		min_cost;
	int		i;

	if (!piles || !piles->head_b || !piles->size_b)
		return (-1);
	i = 0;
	idx_minimum = 0;
	current_cost = ft_calculate_cost2a(piles, i);
	min_cost = current_cost.total;
	i = 1;
	while (i < piles->size_b)
	{
		current_cost = ft_calculate_cost2a(piles, i);
		if (current_cost.total < min_cost)
		{
			min_cost = current_cost.total;
			idx_minimum = i;
		}
		i++;
	}
	return (idx_minimum);
}

int	ft_find_cheapest_to_b(t_piles *piles)
{
	t_cost	current_cost;
	int		idx_minimum;
	int		min_cost;
	int		i;

	if (!piles || !piles->head_a || piles->size_a <= 3)
		return (-1);
	i = 0;
	idx_minimum = 0;
	current_cost = ft_calculate_cost2b(piles, i);
	min_cost = current_cost.total;
	i = 1;
	while (i < piles->size_a)
	{
		current_cost = ft_calculate_cost2b(piles, i);
		if (current_cost.total < min_cost)
		{
			min_cost = current_cost.total;
			idx_minimum = i;
		}
		i++;
	}
	return (idx_minimum);
}
