/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:48:08 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/15 17:38:00 by rluis-ya         ###   ########.fr       */
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

void	ft_print_stack(t_node *p)
{
	if (!p)
		return ;
	while (p->next)
	{
		ft_printf("%d\n", *(p->value));
		p = p->next;
	}
}

int	ft_create_piles(t_env *this)
{
	int		i;
	t_node	*new_node;
	t_piles *tmp_ptr;

	if (!this || !this->size)
		return (-1);
	tmp_ptr = this->pile;
	i = 0;
	while (i < this->size)
	{
		new_node = ft_create_node(&this->nums[i++]);
		if (!new_node || ft_addback_stack(&tmp_ptr->head_a, new_node))
		{
			if (new_node)
				free(new_node->value);
			free(new_node);
			return (-1);
		}
	}
	return (0);
}
