/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:48:08 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:06:09 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_reverserotate_both(t_env *env)
{
	ft_reverse_rotate(&env->pile->head_a);
	ft_reverse_rotate(&env->pile->head_b);
}

void	ft_rotate_both(t_env *env)
{
	ft_rotate(&env->pile->head_a);
	ft_rotate(&env->pile->head_b);
}

void	ft_swap_both(t_env *env)
{
	ft_swap(&env->pile->head_a);
	ft_swap(&env->pile->head_b);
}
