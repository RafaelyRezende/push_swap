/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/09/02 18:51:33 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include <assert.h>

static void	ft_display(t_env *env);
static void	ft_init_env(t_env *env);
//static void	ft_test_calculate_rotation_cost(void);
static void	ft_test_biggest_smallest(void);
static void	ft_init_short(t_env *this, char **av);
static void	ft_init_long(t_env *this, char **av);
static int	ft_check_args(int ac, char **av, t_env *this);
static void	ft_test_find_target(void);
static void ft_test_find_cheapest_to_b(void);
//static void	ft_test_calculate_cost(void);
static void ft_test_find_cheapest_to_a(void);
static void ft_test_calculate_rotation_cost(void);

int	main(void)
{
//	ft_test_calculate_rotation_cost();
	ft_test_biggest_smallest();
	ft_test_find_target();
	ft_test_find_cheapest_to_b();
	ft_test_calculate_rotation_cost();
	ft_test_find_cheapest_to_a();
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
/*
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
*/
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
int	ft_create_test_stack_random(t_env *this, char *test_name, char *nums)
{
	int		argc;
	char	**argv;

	argc = 2;
	argv = malloc(sizeof(char *) * 2);
	if (!argv)
		return (-1);
	//nums = "-23 42 -8 15 -37 29 -46 11 33 -14";
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
void	ft_test_find_target(void)
{
	t_env	this;
	t_node	*current;

	ft_printf("\n\n------------TEST FIND TARGET------------\n\n");
	if (ft_create_test_stack_random(&this, "aaaaaaa", "-23 42 -8 15 -37 29 -46 11 33 -14") < 0)
	{
		ft_printf("Error");
		ft_cleanup_env(&this);
		return ;
	}
	ft_printf("Initial state...\n");
	ft_display(&this);
	ft_push(&this.pile->head_a, &this.pile->head_b);
	ft_push(&this.pile->head_a, &this.pile->head_b);
	ft_push(&this.pile->head_a, &this.pile->head_b);
	ft_push(&this.pile->head_a, &this.pile->head_b);
	ft_printf("\n--------------------------------------------\n");
	ft_display(&this);
	ft_printf("\n--------------------------------------------\n");
	current = this.pile->head_a;
	while (current)
	{
		ft_printf("%d\t", ft_find_target_position_b(this.pile->head_b, *(current->value)));
		current = current->next;
	}
	ft_printf("\n-------------------FINISH-------------------------\n");
	ft_cleanup_env(&this);
}

static 
void	ft_test_biggest_smallest(void)
{
	t_env	this;

	ft_printf("\n\n------------TEST BIGGEST------------\n\n");
	if (ft_create_test_stack_random(&this, "aaaaaaa", "3 1 4 2") < 0)
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
	if (ft_issmallest(this.pile->head_a, -1) == 1)
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
	if (ft_max_pos(this.pile->head_a) == 2)
		ft_printf("MAX POS: OK\n");
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

static
void	free_stack(t_node *head)
{
    t_node *current = head;
    while (current)
    {
        t_node *next = current->next;
        if (current->value)
            free(current->value);
        free(current);
        current = next;
    }
}

static t_node* create_test_node(int value, int idx)
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;

    int *value_ptr = malloc(sizeof(int));
    if (!value_ptr)
    {
        free(node);
        return NULL;
    }

    *value_ptr = value;
    node->value = value_ptr;
    node->idx = idx;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

static t_node* create_stack_from_array(int *values, int size)
{
    if (size <= 0)
        return NULL;

    t_node *head = create_test_node(values[0], 0);
    if (!head)
        return NULL;

    t_node *current = head;
    for (int i = 1; i < size; i++)
    {
        t_node *new_node = create_test_node(values[i], i);
        if (!new_node)
        {
            free_stack(head);
            return NULL;
        }

        current->next = new_node;
        new_node->previous = current;
        current = new_node;
    }

    return head;
}

static
void ft_test_find_cheapest_to_b(void)
{
    printf("Testing ft_find_cheapest_to_b...\n");
    
    // Create test piles structure
    t_piles piles;
    
    // Create stack A with more than 3 elements: [7, 1, 6, 3]
    int values_a[] = {7, 1, 6, 3};
    piles.head_a = create_stack_from_array(values_a, 4);
    piles.size_a = 4;
    
    // Create stack B: [5, 2]
    int values_b[] = {5, 2};
    piles.head_b = create_stack_from_array(values_b, 2);
    piles.size_b = 2;
    
    // Should find a valid index (0-3)
    int index = ft_find_cheapest_to_b(&piles);
    assert(index >= 0 && index < 4);
    
    // Test edge case: stack A with 3 or fewer elements
    piles.size_a = 3;
    index = ft_find_cheapest_to_b(&piles);
    assert(index == -1); // Should return -1
    
    // Test edge case: NULL piles
    index = ft_find_cheapest_to_b(NULL);
    assert(index == -1);
    
    free_stack(piles.head_a);
    free_stack(piles.head_b);
    printf("✓ ft_find_cheapest_to_b tests passed\n\n");
}

static
void ft_test_calculate_rotation_cost(void)
{

    // Basic validation - costs should be non-negative
    assert(cost.ra >= 0);
    assert(cost.rra >= 0);
    assert(cost.rb >= 0);
    assert(cost.rrb >= 0);
    assert(cost.total >= 0);
    assert(cost.pa == 1); // Pushing from B to A
    assert(cost.pb == 0);

    free_stack(piles.head_a);
    free_stack(piles.head_b);
    printf("✓ ft_calculate_cost2a tests passed\n\n");
}

static
void ft_test_find_cheapest_to_a(void)
{
    printf("Testing ft_find_cheapest_to_a...\n");

    // Create test piles structure
    t_piles piles;

    // Create stack A: [1, 3, 5]
    int values_a[] = {1, 3, 5};
    piles.head_a = create_stack_from_array(values_a, 3);
    piles.size_a = 3;

    // Create stack B with elements: [7, 2, 4]
    int values_b[] = {7, 2, 4};
    piles.head_b = create_stack_from_array(values_b, 3);
    piles.size_b = 3;

    // Should find a valid index (0-2)
    int index = ft_find_cheapest_to_a(&piles);
    assert(index >= 0 && index < 3);

    // Test edge case: empty stack B
    free_stack(piles.head_b);
    piles.head_b = NULL;
    piles.size_b = 0;
    index = ft_find_cheapest_to_a(&piles);
    assert(index == -1); // Should return -1

    // Test edge case: NULL piles
    index = ft_find_cheapest_to_a(NULL);
    assert(index == -1);

    free_stack(piles.head_a);
    printf("✓ ft_find_cheapest_to_a tests passed\n\n");
}
/*
static
void	ft_test_calculate_cost(void)
{
}
*/
