/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:39:33 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/06 17:06:03 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"


typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	**stack_a;
	t_node	**stack_b;
}	t_stack;
#endif
