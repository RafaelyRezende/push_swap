/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:39:33 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/03 18:54:00 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int				*value;
	int				idx;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_cost
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	pa;
	int	pb;
	int	total;
}	t_cost;

typedef struct s_piles
{
	t_node	*head_a;
	t_node	*head_b;
	int		size_a;
	int		size_b;
}	t_piles;

typedef struct s_env
{
	t_piles	*pile;
	int		size;
	int		*nums;
}	t_env;
/* Helper functions */
long long	ft_strtol(const char *nptr);
int			ft_isdup(int n1, int *set, int size);
int			ft_split_size(char **split);
int			*ft_cast_arr(long *arr_nums, int size);
long		*ft_check_overflow(char **split, int size);
int			ft_get_nums(t_env *this, const char *str);
void		ft_exit_split(char **split);
void		ft_exit_clean(char **split, long *arr_nums);
/* Node functions */
t_node		*ft_create_node(int *val);
int			ft_addback_stack(t_node **head, t_node *to_add, int idx);
int			ft_create_piles(t_env *this);
void		ft_print_stack(t_node *p);
/* Memory management */
void		ft_cleanup_node(t_node **node_addr);
void		ft_cleanup_stack(t_node **head);
void		ft_cleanup_env(t_env *env);
/* Operations */
void		ft_swap(t_node **head);
void		ft_push(t_node **src, t_node **dst);
void		ft_rotate(t_node **head);
void		ft_reverse_rotate(t_node **head);
void		ft_reverserotate_both(t_env *env);
void		ft_rotate_both(t_env *env);
void		ft_swap_both(t_env *env);
/* Helper operations */
int			ft_issorted(t_node **head);
int			ft_stack_size(t_node **head);
void		ft_reset_index(t_node **head);
/* Cost functions */
void		ft_calculate_rotation_cost(int stack_size, \
int target_position, int *rotate, int *reverse_rotate);
int			ft_find_target_position_b(t_node *stack, int value);
int			ft_find_target_position_a(t_node *stack, int value);
int			ft_isbiggest(t_node *stack, int value);
int			ft_issmallest(t_node *stack, int value);
int			ft_max_pos(t_node *stack);
int			ft_min_pos(t_node *stack);
int			ft_find_cheapest_to_a(t_piles *piles);
int			ft_find_cheapest_to_b(t_piles *piles);
//int			ft_find_min_diff(t_env *this);
t_cost		ft_calculate_cost2b(t_piles *piles, int index_a);
t_cost		ft_calculate_cost2a(t_piles *piles, int index_b);
void		ft_get_total_cost(t_cost *cost);
int			ft_get_value_by_index(t_node *head, int idx);
void		ft_init_cost(t_cost *cost, const char *flag);
/* Driver functions */
void		ft_execute_moves2b(t_env *this, int idx);
void		ft_execute_moves2a(t_env *this, int idx);
void		ft_driver(t_env *this);
void		ft_init_sort(t_env *this);
void		ft_passthrough_a2b(t_env *this);
void		ft_passthrough_b2a(t_env *this);
void		ft_tinysort(t_node **head_a);
void		ft_end_position(t_env *this);
void		ft_display(t_env *env);
#endif
