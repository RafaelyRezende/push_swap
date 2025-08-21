/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/14 13:44:17 by rluis-ya         ###   ########.fr       */
=======
/*   Updated: 2025/08/19 09:00:04 by rluis-ya         ###   ########.fr       */
>>>>>>> feature/stack_moves
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void ft_init_env(t_env *env);
static void	ft_init_short(t_env *this, char **av);
static void	ft_init_long(t_env *this, char **av);
static int	ft_check_args(int ac, char **av, t_env *this);
static void	ft_display(t_env *env);
static void	ft_loop(t_env *env);
static void ft_clear_screen(void);

int	main(int argc, char **argv)
{
	t_env	this;

	ft_init_env(&this);
	if (ft_check_args(argc, argv, &this))
		return (-1);
	if (ft_create_piles(&this))
		return (-1);
	ft_display(&this);
	ft_loop(&this);
	ft_cleanup_env(&this);
	return (0);
}

static
void	ft_display(t_env *env)
{
	ft_printf("\t\tStack A\n\n");
	ft_print_stack(env->pile->head_a);
	ft_printf("\n\t\tStack B\n\n");
	ft_print_stack(env->pile->head_b);
}

static
void ft_init_env(t_env *env)
{
	if (!env)
		return;
	env->pile = NULL;
	env->nums = NULL;
	env->size = 0;
	env->pile = ft_calloc(1, sizeof(t_piles));
	if (!env->pile)
		ft_exit_error("Memory allocation failed\n");
	env->pile->head_a = NULL;
	env->pile->head_b = NULL;
}

static
void	ft_init_short(t_env *this, char **av)
{
	this->nums = NULL;
	if (ft_get_nums(this, av[1]) || !this->nums)
		ft_putstr_fd("Error\n", 2);
}

static
void	ft_init_long(t_env *this, char **av)
{
	int			i;
	long long	l_tmp;

	i = 0;
	this->size = ft_split_size(av) - 1;
	this->nums = (int *)ft_calloc(this->size, sizeof(int));
	if (!this->nums)
		return (ft_putstr_fd("Error\n", 2));
	while (i < this->size)
	{
		l_tmp = ft_strtol(av[i + 1]);
		if (l_tmp == LONG_MAX)
			return(ft_putstr_fd("Error\n", 2));
		this->nums[i] = (int)l_tmp;
		if (ft_isdup(this->nums[i], this->nums, i) && i != 0)
		{
			free(this->nums);
			this->nums = NULL;
			return (ft_putstr_fd("Error\n", 2));
		}
		i++;
	}
}

static
int	ft_check_args(int ac, char **av, t_env *this)
{
	if (ac == 2)
	{
		ft_init_short(this, av);
		return (0);
	}
	if (ac > 2)
	{
		ft_init_long(this, av);
		return (0);
	}
	return (-1);
}

static
void	ft_loop(t_env *env)
{
	char	*buff;
	char	*prev_move;
	int		count;

	count = 0;
	prev_move = NULL;
	while (1)
	{
		ft_clear_screen();
		ft_display(env);
		buff = NULL;

		if (ft_issorted(&env->pile->head_a) && (ft_stack_size(&env->pile->head_a) == env->size))
		{
			free(prev_move);
			free(buff);
			ft_printf("Move count: %d | ", count);
			ft_putstr_fd("OK\n", 1);
			break ;
		}
		if (prev_move)
		{
			ft_printf("Move count: %d | ", count);
			ft_printf("Previous move: %s | ", prev_move);
		}
		ft_printf("Next move: ");
		buff = get_next_line(0);
		if (!buff || !ft_strcmp(buff, "exit\n") || !ft_strcmp(buff, "q\n"))
		{
			free(prev_move);
			free(buff);
			break ;
		}
		if (!ft_strcmp(buff, "sa\n") || !ft_strcmp(buff, "sb\n") ||
			ft_strcmp(buff, "ss\n") || !ft_strcmp(buff, "pa\n") ||
			!ft_strcmp(buff, "pb\n") || !ft_strcmp(buff, "ra\n") ||
			!ft_strcmp(buff, "rb\n") || !ft_strcmp(buff, "rr\n") ||
			!ft_strcmp(buff, "rra\n") || !ft_strcmp(buff, "rrb\n") ||
			!ft_strcmp(buff, "rrr\n"))
		{
			free(prev_move);
			prev_move = strndup(buff, ft_strlen(buff) - 1);
			if (!ft_strcmp(buff, "sa\n"))
				ft_swap(&env->pile->head_a);
			if (!ft_strcmp(buff, "sb\n"))
				ft_swap(&env->pile->head_b);
			if (!ft_strcmp(buff, "ss\n"))
				ft_swap_both(env);
			if (!ft_strcmp(buff, "pa\n"))
				ft_push(&env->pile->head_b, &env->pile->head_a);
			if (!ft_strcmp(buff, "pb\n"))
				ft_push(&env->pile->head_a, &env->pile->head_b);
			if (!ft_strcmp(buff, "ra\n"))
				ft_rotate(&env->pile->head_a);
			if (!ft_strcmp(buff, "rb\n"))
				ft_rotate(&env->pile->head_b);
			if (!ft_strcmp(buff, "rr\n"))
				ft_rotate_both(env);
			if (!ft_strcmp(buff, "rra\n"))
				ft_reverse_rotate(&env->pile->head_a);
			if (!ft_strcmp(buff, "rrb\n"))
				ft_reverse_rotate(&env->pile->head_b);
			if (!ft_strcmp(buff, "rrr\n"))
				ft_reverserotate_both(env);
			count++;
		}
		else
		{
			ft_printf("Invalid move. Use sa, sb, ss, pa, pb.\n");
			free(buff);
			continue ;
		}
		free(buff);
	}
}

static
void ft_clear_screen(void)
{
    printf("\033[H\033[J");  // ANSI escape: Home + Clear screen
    fflush(stdout);
}
