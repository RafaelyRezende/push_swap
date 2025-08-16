/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:33:59 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/16 19:51:10 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	ft_swap(t_node **head)
{
	t_node	*tmp;

	if (!head || !*head || !(*head)->next)
		return (-1);
	tmp = (*head)->next;
	tmp->previous = NULL;
	printf("nil ----> %p\n", (*head)->previous);
	if (tmp->next)
	{
		(*head)->next = tmp->next;
		//(*head)->next->next->previous = *head;
		tmp->next->previous = *head;
	}
	else
		(*head)->next = NULL;
	(*head)->previous = tmp;
	tmp->next = *head;
	*head = tmp;
	return (0);
}
