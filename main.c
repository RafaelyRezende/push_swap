/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/09/03 20:42:47 by rluis-ya         ###   ########.fr       */
=======
/*   Updated: 2025/09/03 20:51:13 by rluis-ya         ###   ########.fr       */
>>>>>>> develop
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void	ft_init_env(t_env *env);
static int	ft_init_short(t_env *this, char **av);
static int	ft_init_long(t_env *this, char **av);
static int	ft_check_args(int ac, char **av, t_env *this);

int	main(int argc, char **argv)
{
	t_env	this;

	ft_init_env(&this);
	if (ft_check_args(argc, argv, &this))
		return (-1);
	if (ft_create_piles(&this))
		return (-1);
	if (ft_issorted(&this.pile->head_a))
		return (0);
	ft_driver(&this);
	ft_cleanup_env(&this);
	return (0);
}

static
void	ft_init_env(t_env *env)
{
	if (!env)
		return ;
	env->pile = NULL;
	env->nums = NULL;
	env->size = 0;
	env->pile = ft_calloc(1, sizeof(t_piles));
	if (!env->pile)
		ft_printf("Memory allocation failed\n");
	env->pile->head_a = NULL;
	env->pile->head_b = NULL;
}

static
int	ft_init_short(t_env *this, char **av)
{
	this->nums = NULL;
	if (!av[1][0])
		return (ft_putstr_fd("Error\n", 2), -1);
	if (ft_get_nums(this, av[1]) || !this->nums)
		return (ft_putstr_fd("Error\n", 2), -1);
	return (0);
}

static
int	ft_init_long(t_env *this, char **av)
{
	int			i;
	long long	l_tmp;

	i = 0;
	this->size = ft_split_size(av) - 1;
	this->nums = (int *)ft_calloc(this->size, sizeof(int));
	if (!this->nums)
		return (ft_putstr_fd("Error\n", 2), -1);
	while (i < this->size)
	{
		l_tmp = ft_strtol(av[i + 1]);
		if (l_tmp == LONG_MAX)
			return (ft_putstr_fd("Error\n", 2), -1);
		this->nums[i] = (int)l_tmp;
		if (ft_isdup(this->nums[i], this->nums, i) && i != 0)
		{
			return (ft_putstr_fd("Error\n", 2), -1);
		}
		i++;
	}
	return (0);
}

static
int	ft_check_args(int ac, char **av, t_env *this)
{
	if (ac == 2)
	{
		if (ft_init_short(this, av) < 0)
		{
			ft_cleanup_env(this);
			return (-1);
		}
		return (0);
	}
	if (ac > 2)
	{
		if (ft_init_long(this, av) < 0)
		{
			ft_cleanup_env(this);
			return (-1);
		}
	}
	return (0);
}
