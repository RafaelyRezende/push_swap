/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:12:33 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/01 16:39:37 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

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
	return (max->idx);
}

int	ft_find_target_position_b(t_node *stack, int value)
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

int	ft_find_target_position_a(t_node *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->next)
		return (0);
	current = stack;
	while (current && current->next)
	{
		if (*(current->value) < value && *(current->next->value) > value)
			return (current->next->idx);
		current = current->next;
	}
	if (ft_isbiggest(stack, value))
		return (current->idx + 1);
	return (0);
}
