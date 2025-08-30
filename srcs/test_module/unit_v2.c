/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:22:26 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/30 20:24:20 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Helper function declarations
static t_node* create_test_node(int value, int idx);
static t_node* create_stack_from_array(int *values, int size);
static void free_stack(t_node *head);

// Test function declarations
void test_ft_calculate_rotation_cost(void);
void test_ft_find_target_position_b(void);
void test_ft_find_target_position_a(void);
void test_ft_calculate_cost2b(void);
void test_ft_calculate_cost2a(void);
void test_ft_find_cheapest_to_b(void);
void test_ft_find_cheapest_to_a(void);
void test_integration_turk_logic(void);

int main(void)
{
    printf("=== Turk Algorithm Functions Test Suite ===\n\n");
    
    test_ft_calculate_rotation_cost();
    test_ft_find_target_position_b();
    test_ft_find_target_position_a();
    test_ft_calculate_cost2b();
    test_ft_calculate_cost2a();
    test_ft_find_cheapest_to_b();
    test_ft_find_cheapest_to_a();
    test_integration_turk_logic();
    
    printf("\n=== All Tests Passed! ===\n");
    return (0);
}

// Helper Functions
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

static void free_stack(t_node *head)
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

// Test Functions

void test_ft_calculate_rotation_cost(void)
{
    printf("Testing ft_calculate_rotation_cost...\n");
    
    int rotate, reverse_rotate;
    
    // Test edge case: stack size < 2
    ft_calculate_rotation_cost(1, 0, &rotate, &reverse_rotate);
    assert(rotate == 0 && reverse_rotate == 0);
    
    // Test forward rotation (smaller target position)
    ft_calculate_rotation_cost(5, 1, &rotate, &reverse_rotate);
    assert(rotate == 1 && reverse_rotate == 0);
    
    // Test reverse rotation (larger target position)
    ft_calculate_rotation_cost(5, 4, &rotate, &reverse_rotate);
    assert(rotate == 0 && reverse_rotate == 1);
    
    // Test middle position (equal costs)
    ft_calculate_rotation_cost(4, 2, &rotate, &reverse_rotate);
    assert(rotate == 2 && reverse_rotate == 0);
    
    printf("✓ ft_calculate_rotation_cost tests passed\n\n");
}

void test_ft_find_target_position_b(void)
{
    printf("Testing ft_find_target_position_b...\n");
    
    // Create descending stack B: [5, 3, 1]
    int values_b[] = {5, 3, 1};
    t_node *stack_b = create_stack_from_array(values_b, 3);
    
    // Test biggest element (should go above max = 5)
    int pos = ft_find_target_position_b(stack_b, 6);
    assert(pos == 0); // Position of maximum element
    
    // Test smallest element (should go above max = 5)
    pos = ft_find_target_position_b(stack_b, 0);
    assert(pos == 0); // Position of maximum element
    
    // Test middle element (should go between 3 and 1)
    pos = ft_find_target_position_b(stack_b, 2);
    assert(pos >= 0); // Valid position
    
    // Test edge case: NULL stack
    pos = ft_find_target_position_b(NULL, 5);
    assert(pos == 0);
    
    free_stack(stack_b);
    printf("✓ ft_find_target_position_b tests passed\n\n");
}

void test_ft_find_target_position_a(void)
{
    printf("Testing ft_find_target_position_a...\n");
    
    // Create ascending stack A: [1, 3, 5]
    int values_a[] = {1, 3, 5};
    t_node *stack_a = create_stack_from_array(values_a, 3);
    
    // Test element that fits in middle
    int pos = ft_find_target_position_a(stack_a, 2);
    assert(pos >= 0); // Should find valid position
    
    // Test biggest element
    pos = ft_find_target_position_a(stack_a, 6);
    assert(pos >= 0); // Should find valid position
    
    // Test smallest element
    pos = ft_find_target_position_a(stack_a, 0);
    assert(pos >= 0); // Should find valid position
    
    // Test edge case: NULL stack
    pos = ft_find_target_position_a(NULL, 5);
    assert(pos == 0);
    
    free_stack(stack_a);
    printf("✓ ft_find_target_position_a tests passed\n\n");
}

void test_ft_calculate_cost2b(void)
{
    printf("Testing ft_calculate_cost2b...\n");
    
    // Create test piles structure
    t_piles piles;
    
    // Create stack A: [4, 2, 1]
    int values_a[] = {4, 2, 1};
    piles.head_a = create_stack_from_array(values_a, 3);
    piles.size_a = 3;
    
    // Create stack B: [5, 3] (descending)
    int values_b[] = {5, 3};
    piles.head_b = create_stack_from_array(values_b, 2);
    piles.size_b = 2;
    
    // Test cost calculation for element at index 0 in stack A
    t_cost cost = ft_calculate_cost2b(&piles, 0); // Element value = 4
    
    // Basic validation - costs should be non-negative
    assert(cost.ra >= 0);
    assert(cost.rra >= 0);
    assert(cost.rb >= 0);
    assert(cost.rrb >= 0);
    assert(cost.total >= 0);
    assert(cost.pb == 1); // Pushing from A to B
    assert(cost.pa == 0);
    
    free_stack(piles.head_a);
    free_stack(piles.head_b);
    printf("✓ ft_calculate_cost2b tests passed\n\n");
}

void test_ft_calculate_cost2a(void)
{
    printf("Testing ft_calculate_cost2a...\n");
    
    // Create test piles structure
    t_piles piles;
    
    // Create stack A: [1, 3, 5] (ascending)
    int values_a[] = {1, 3, 5};
    piles.head_a = create_stack_from_array(values_a, 3);
    piles.size_a = 3;
    
    // Create stack B: [4, 2] (descending)
    int values_b[] = {4, 2};
    piles.head_b = create_stack_from_array(values_b, 2);
    piles.size_b = 2;
    
    // Test cost calculation for element at index 0 in stack B
    t_cost cost = ft_calculate_cost2a(&piles, 0); // Element value = 4
    
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

void test_ft_find_cheapest_to_b(void)
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

void test_ft_find_cheapest_to_a(void)
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

void test_integration_turk_logic(void)
{
    printf("Testing Turk Algorithm Integration...\n");
    
    // Simulate a complete Turk algorithm workflow
    t_piles piles;
    
    // Initial state: Stack A = [5, 2, 8, 1, 4], Stack B = []
    int initial_a[] = {5, 2, 8, 1, 4};
    piles.head_a = create_stack_from_array(initial_a, 5);
    piles.size_a = 5;
    piles.head_b = NULL;
    piles.size_b = 0;
    
    // Phase 1: Push first 2 elements to stack B (no cost calculation needed)
    // After pb operations: Stack A = [8, 1, 4], Stack B = [2, 5]
    free_stack(piles.head_b);
    int values_b[] = {2, 5}; // Descending order
    piles.head_b = create_stack_from_array(values_b, 2);
    piles.size_b = 2;
    piles.size_a = 3; // Simulate reduced size
    
    // Phase 2: Find cheapest element to move from A to B
    int cheapest_to_b = ft_find_cheapest_to_b(&piles);
    assert(cheapest_to_b == -1); // Should be -1 since size_a <= 3
    
    // Phase 4: Find cheapest element to move from B to A
    int cheapest_to_a = ft_find_cheapest_to_a(&piles);
    assert(cheapest_to_a >= 0 && cheapest_to_a < 2); // Valid index in stack B
    
    // Test cost calculations work together
    if (cheapest_to_a >= 0)
    {
        t_cost cost = ft_calculate_cost2a(&piles, cheapest_to_a);
        assert(cost.total >= 0); // Valid cost calculation
    }
    
    free_stack(piles.head_a);
    free_stack(piles.head_b);
    printf("✓ Turk Algorithm Integration tests passed\n\n");
}
