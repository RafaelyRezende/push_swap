/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/12 17:31:05 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stacks;

	if (argc < 2)
		return (-1);
	else if (argc == 2)
		stacks = ft_parser(argc, argv[1]);
	else
	{
	}
	free(stacks);
	return (0);
}
