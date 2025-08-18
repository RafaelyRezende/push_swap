/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:03:47 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/18 18:12:24 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_exit_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_exit_clean(char **split, long *arr_nums)
{
	if (arr_nums)
		free(arr_nums);
	if (split)
		ft_exit_split(split);
}

void	ft_cleanup_node(t_node **node_addr)
{
	t_node	*node;

	if (!node_addr || !*node_addr)
		return ;
	node = *node_addr;
	if (node->value)
		free(node->value);
	free(node);
	*node_addr = NULL;
}

void	ft_cleanup_stack(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		ft_cleanup_node(&current);
		current = next;
	}
	*head = NULL;
}

void	ft_cleanup_env(t_env *env)
{
	if (!env)
		return ;
	if (env->pile)
	{
		ft_cleanup_stack(&env->pile->head_a);
		ft_cleanup_stack(&env->pile->head_b);
		free(env->pile);
		env->pile = NULL;
	}
	if (env->nums)
	{
		free(env->nums);
		env->nums = NULL;
	}
}

void	ft_exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
}
