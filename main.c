/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/16 19:29:39 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void ft_init_env(t_env *env);
static void	ft_init_short(t_env *this, char **av);
static void	ft_init_long(t_env *this, char **av);
static int	ft_check_args(int ac, char **av, t_env *this);
static void	ft_display(t_env *env);

int	main(int argc, char **argv)
{
	t_env	this;
	char	*buff;

	ft_init_env(&this);
	buff = NULL;
	if (ft_check_args(argc, argv, &this))
		return (-1);
	if (ft_create_piles(&this))
		return (-1);
	ft_display(&this);
	ft_swap(&this.pile->head_a);
	ft_display(&this);
	ft_cleanup_env(&this);
	return (0);
}

static
void	ft_display(t_env *env)
{
	ft_printf("Stack A\n\n");
	ft_print_stack(env->pile->head_a);
	ft_printf("\nStack B\n\n");
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
	int	i;

	i = 0;
	this->size = ft_split_size(av) - 1;
	this->nums = (int *)ft_calloc(this->size, sizeof(int));
	if (!this->nums)
		return (ft_putstr_fd("Error\n", 2));
	while (i < this->size)
	{
		this->nums[i] = ft_strtol(av[i + 1]);
		if (ft_isdup(this->nums[i], this->nums, this->size))
		{
			free(this->nums);
			this->nums = NULL;
			return (ft_putstr_fd("Error\n", 2));
		}
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
