/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/14 13:44:17 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void	ft_init_short(t_env *this, char **av);
static void	ft_init_long(t_env *this, char **av);
static int	ft_check_args(int ac, char **av, t_env *this);

int	main(int argc, char **argv)
{
	t_env	this;

	return (ft_check_args(argc, argv, &this));
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
		if (this->nums)
			free(this->nums);
		return (0);
	}
	if (ac > 2)
	{
		ft_init_long(this, av);
		if (this->nums)
			free(this->nums);
		return (0);
	}
	return (-1);
}
