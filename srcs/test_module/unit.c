/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/29 15:32:41 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void	ft_display(t_env *env);
static void	ft_init_env(t_env *env);
static void	ft_test_calculate_rotation_cost(void);
static void	ft_test_biggest_smallest(void);
static void	ft_init_short(t_env *this, char **av);
static void	ft_init_long(t_env *this, char **av);
static int	ft_check_args(int ac, char **av, t_env *this);

int	main(void)
{
	ft_test_calculate_rotation_cost();
	ft_test_biggest_smallest();
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

static void	ft_test_calculate_rotation_cost(void)
{
	ft_printf("\n\n------------TEST ROTATION COST------------\n\n");
	if (ft_calculate_rotation_cost(1, 0) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_calculate_rotation_cost(0, 0) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_calculate_rotation_cost(5, 2) == 2)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_calculate_rotation_cost(5, 4) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_calculate_rotation_cost(10, 5) == 5)
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_printf("\n\n------------FINISHED ROTATION COST------------\n\n");
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
int	ft_create_test_stack_3142(t_env *this)
{
	int		argc;
	char	*test_name;
	char	*nums;
	char	**argv;

	argc = 2;
	argv = malloc(sizeof(char *) * 2);
	if (!argv)
		return (-1);
	test_name = malloc(sizeof(char) * 7);
	if (!test_name)
		return (free(argv), -1);
	nums = malloc(sizeof(char) * 7);
	if (!nums)
		return (free(test_name), free(argv), -1);
	test_name = "aaaaaaa";
	nums = "3 1 4 2";
	argv[0] = test_name;
	argv[1] = nums;
	ft_init_env(this);
	if (ft_check_args(argc, argv, this))
		return (-1);
	if (ft_create_piles(this))
		return (-1);
	return (0);
}

static 
void	ft_test_biggest_smallest(void)
{
	t_env	this;

	ft_printf("\n\n------------TEST BIGGEST------------\n\n");
	if (ft_create_test_stack_3142(&this) < 0)
	{
		ft_printf("Error");
		ft_cleanup_env(&this);
		return ;
	}
	ft_display(&this);
	if (ft_isbiggest(this.pile->head_a, 5) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_isbiggest(this.pile->head_a, 4) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_isbiggest(this.pile->head_a, 3) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_isbiggest(this.pile->head_a, 0) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_issmallest(this.pile->head_a, 0) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_issmallest(this.pile->head_a, 1) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_issmallest(this.pile->head_a, 5) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_isbiggest(NULL, 5) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ft_issmallest(NULL, 1) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("\n\n------------FINISHED------------\n\n");
	ft_cleanup_env(&this);
}

static
void    ft_init_short(t_env *this, char **av)
{
        this->nums = NULL;
        if (ft_get_nums(this, av[1]) || !this->nums)
                ft_putstr_fd("Error\n", 2);
}

static
void    ft_init_long(t_env *this, char **av)
{
        int                     i;
        long long       l_tmp;

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
int     ft_check_args(int ac, char **av, t_env *this)
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
