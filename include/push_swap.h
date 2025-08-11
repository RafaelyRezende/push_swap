/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:39:33 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/11 14:02:23 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	void			*value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	**stack_a;
	t_node	**stack_b;
}	t_stack;
/******************************************************************************
 *************************    FUNCTIONS    ************************************
 *****************************************************************************/
int	ft_error_check(char *str);
int	ft_errmsg(void);
int	*ft_parser(char **av, int size_numbers);
#endif
