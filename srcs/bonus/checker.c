/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/06 12:44:05 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	ft_checker(t_env *this)
{
	int		fd;
	char	*str;

	fd = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (ft_driver_bonus(this, str) < 0)
		{
			ft_putstr_fd("Error\n", 2);
			free(str);
			return ;
		}
		free(str);
	}
	if (ft_issorted(&this->pile->head_a) && !this->pile->head_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	ft_driver_bonus(t_env *this, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		ft_push(&this->pile->head_b, &this->pile->head_a);
	else if (!ft_strcmp(str, "pb\n"))
		ft_push(&this->pile->head_a, &this->pile->head_b);
	else if (!ft_strcmp(str, "sa\n"))
		ft_swap(&this->pile->head_a);
	else if (!ft_strcmp(str, "sb\n"))
		ft_swap(&this->pile->head_b);
	else if (!ft_strcmp(str, "ra\n"))
		ft_rotate(&this->pile->head_a);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rotate(&this->pile->head_b);
	else if (!ft_strcmp(str, "rra\n"))
		ft_reverse_rotate(&this->pile->head_a);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_reverse_rotate(&this->pile->head_b);
	else if (!ft_strcmp(str, "ss\n"))
		ft_swap_both(this);
	else if (!ft_strcmp(str, "rr\n"))
		ft_rotate_both(this);
	else if (!ft_strcmp(str, "rrr\n"))
		ft_reverserotate_both(this);
	else
		return (-1);
	return (1);
}
