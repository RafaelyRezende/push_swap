/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:33:59 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/16 22:05:19 by rluis-ya         ###   ########.fr       */
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
