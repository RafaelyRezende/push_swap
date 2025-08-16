/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:39:33 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/16 15:17:21 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int				*value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_piles
{
	t_node	*head_a;
	t_node	*head_b;
}	t_piles;

typedef struct s_env
{
	t_piles	*pile;
	int		size;
	int		*nums;
}	t_env;
/******************************************************************************
 *************************    FUNCTIONS    ************************************
 *****************************************************************************/
long long	ft_strtol(const char *nptr);
int			ft_isdup(int n1, int *set, int size);
int			ft_split_size(char **split);
int			*ft_cast_arr(long *arr_nums, int size);
long		*ft_check_overflow(char **split, int size);
int			ft_get_nums(t_env *this, const char *str);
void		ft_exit_split(char **split);
void		ft_exit_clean(char **split, long *arr_nums);
t_node		*ft_create_node(int *val);
int			ft_addback_stack(t_node **head, t_node *to_add);
int			ft_create_piles(t_env *this);
void		ft_print_stack(t_node *p);
void		ft_exit_error(char *msg);
void		ft_cleanup_node(t_node **node_addr);
void		ft_cleanup_stack(t_node **head);
void		ft_cleanup_env(t_env *env);
#endif
