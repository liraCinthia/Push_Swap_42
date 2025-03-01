/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:25:26 by clira-ne          #+#    #+#             */
/*   Updated: 2024/08/01 20:48:45 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_to_stack_b(t_stack **a_stack, t_stack **b_stack)
{
	int	stack_size;
	int	middle;

	stack_size = ft_get_stack_size(*a_stack);
	while (stack_size > 3)
	{
		stack_size = ft_get_stack_size(*a_stack);
		middle = ft_indexes_average(*a_stack);
		if (stack_size == 3)
			break ;
		if ((*a_stack)->index <= middle)
			ft_make_push_b(a_stack, b_stack);
		else
			ft_make_rotate_a(a_stack);
	}
}

void	ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	ft_push_to_stack_b(a_stack, b_stack);
	ft_sort_small(a_stack);
	while (*b_stack)
	{
		ft_have_position(a_stack);
		ft_have_position(b_stack);
		ft_have_target_position(a_stack, b_stack);
		ft_get_cost(a_stack, b_stack);
		ft_calc_total_cost(a_stack, b_stack);
		ft_get_best_operation(a_stack, b_stack);
	}
	ft_have_position(a_stack);
	if (ft_is_sorted(*a_stack) == 1)
		ft_sorting_stack_a(a_stack);
}

void	ft_sorting_stack_a(t_stack **a_stack)
{
	int	stack_size;
	int	low_position;

	stack_size = ft_get_stack_size(*a_stack);
	low_position = ft_lowest_position(*a_stack);
	if (low_position > stack_size / 2)
	{
		while (low_position < stack_size)
		{
			ft_make_reverse_rotate_a(a_stack);
			low_position++;
		}
	}
	else
	{
		while (low_position != 0)
		{
			ft_make_rotate_a(a_stack);
			low_position--;
		}
	}
}

void	ft_sort_small(t_stack **stack)
{
	if ((*stack)->index == ft_largest_index_value(*stack))
		ft_make_rotate_a(stack);
	else if ((*stack)->next->index == ft_largest_index_value(*stack))
		ft_make_reverse_rotate_a(stack);
	if (ft_is_sorted(*stack) == 1)
		ft_make_swap_a(stack);
}
