/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/11 11:05:54 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stacks;

	if (argc <= 2)
		return (-1);
	if (argc > 2)
	{
		stacks = ft_parser(argv, argc);
		if (!stacks)
		{
			ft_printf("Error: only numbers allowed.");
			return (-1);
		}
	}
	i = 0;
	free(stacks);
	return (0);
}
