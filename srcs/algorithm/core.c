/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:12:33 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/29 15:01:47 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	ft_calculate_rotation_cost(int stack_size, int target_position)
{
	int	forward_cost;
	int	backward_cost;

	if (stack_size < 2)
		return (0);
	forward_cost = target_position;
	backward_cost = stack_size - target_position;
	if (forward_cost <= backward_cost)
		return (forward_cost);
	return (backward_cost);
}

int	ft_isbiggest(t_node *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->next)
		return (0);
	current = stack;
	while (current)
	{
		if (*(current->value) > value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_issmallest(t_node *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->next)
		return (0);
	current = stack;
	while (current)
	{
		if (*(current->value) < value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_max_pos(t_node *stack)
{
	t_node	*current;
	t_node	*max;

	if (!stack || !stack->next)
		return (0);
	current = stack;
	max = stack;
	while (current)
	{
		if (*(max->value) < *(current->value))
			max = current;
		current = current->next;
	}
	if (!max->next)
		return (0);
	return (max->idx);
}

int	ft_find_target_position(t_node *stack, int value)
{
	t_node	*current;

	if (!stack)
		return (0);
	if (ft_isbiggest(stack, value) || ft_issmallest(stack, value))
		return (ft_max_pos(stack));
	current = stack;
	while (current && current->next)
	{
		if (*(current->value) > value && *(current->next->value) < value)
			return (current->next->idx);
		current = current->next;
	}
	return (0);
}
