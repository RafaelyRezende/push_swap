/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:33:59 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/18 21:36:45 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_swap(t_node **head)
{
	t_node	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	tmp->previous = NULL;
	if (tmp->next)
	{
		(*head)->next = tmp->next;
		tmp->next->previous = *head;
	}
	else
		(*head)->next = NULL;
	(*head)->previous = tmp;
	tmp->next = *head;
	*head = tmp;
}

void	ft_push(t_node **src, t_node **dst)
{
	t_node	*node_to_move;

	if (!src || !dst || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	node_to_move->next = *dst;
	if (*dst)
		(*dst)->previous = node_to_move;
	*dst = node_to_move;
}

void	ft_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	(*head)->previous = NULL;
	last = (*head);
	while (last->next)
		last = last->next;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	ft_reverse_rotate(t_node **head)
{
	t_node	*second;
	t_node	*new_last;

	if (!head || !*head || !(*head)->next)
		return ;
	second = *head;
	while ((*head)->next)
		*head = (*head)->next;
	new_last = (*head)->previous;
	new_last->next = NULL;
	(*head)->next = second;
	(*head)->previous = NULL;
	second->previous = *head;
}

int	ft_issorted(t_node **head)
{
	t_node	*current;

	if (!head || !*head)
		return (0);
	current = (*head)->next;
	while (current)
	{
		if (*current->value < *current->previous->value)
			return (0);
		else
			current = current->next;
	}
	return (1);
}

int	ft_stack_size(t_node **head)
{
	t_node	*current;
	int		i;

	if (!head || !*head)
		return (0);
	current = *head;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
