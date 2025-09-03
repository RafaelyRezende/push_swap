/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:33:59 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:10:38 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

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

void	ft_reset_index(t_node **head)
{
	int		i;
	t_node	*current;

	if (!head || !*head)
		return ;
	current = *head;
	i = 0;
	while (current)
	{
		current->idx = i++;
		current = current->next;
	}
}
