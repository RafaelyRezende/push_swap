/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:48:08 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/16 15:15:47 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

t_node	*ft_create_node(int	*val)
{
	t_node	*tmp_node;
	int		*tmp_int;

	tmp_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!tmp_node)
		return (NULL);
	tmp_int = (int *)ft_calloc(1, sizeof(int));
	if (!tmp_int)
		return (free(tmp_node), NULL);
	*tmp_int = *val;
	tmp_node->value = tmp_int;
	tmp_node->next = NULL;
	tmp_node->previous = NULL;
	return (tmp_node);
}

int	ft_addback_stack(t_node **head, t_node *to_add)
{
	t_node	*tail;

	if (!to_add)
		return (-1);
	if (!*head && to_add)
	{
		*head = to_add;
		return (0);
	}
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = to_add;
	to_add->previous = tail;
	return (0);
}
/*
 * * Print node value one by one
 * */
void	ft_print_stack(t_node *p)
{
	while (p)
	{
		ft_printf("%d\n", *(p->value));
		p = p->next;
	}
}
/*
 * Used only once to initialize both stacks
 */
int	ft_create_piles(t_env *this)
{
	int		i;
	t_node	*new_node;

	if (!this || !this->nums || !this->pile || this->size <= 0)
		return (-1);
	i = 0;
	while (i < this->size)
	{
		new_node = ft_create_node(&this->nums[i]);
		if (!new_node || ft_addback_stack(&this->pile->head_a, new_node))
		{
			if (new_node)
				ft_cleanup_stack(&this->pile->head_a);
			return (-1);
		}
		i++;
	}
	return (0);
}
