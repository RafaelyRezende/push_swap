/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:55:46 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:00:48 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

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
