/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:36:49 by clira-ne          #+#    #+#             */
/*   Updated: 2024/08/01 20:38:07 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;

	if (!stack || !(*stack)->next)
		return ;
	top = *stack;
	second = (*stack)->next;
	top->next = second->next;
	second->next = top;
	*stack = second;
}

void	ft_make_swap_a(t_stack **a_stack)
{
	ft_swap(a_stack);
	ft_putstr_fd("sa\n", 1);
}

void	ft_make_swap_b(t_stack **b_stack)
{
	ft_swap(b_stack);
	ft_putstr_fd("sb\n", 1);
}

void	ft_make_swap_a_and_b(t_stack **a_stack, t_stack **b_stack)
{
	ft_swap(a_stack);
	ft_swap(b_stack);
	ft_putstr_fd("ss\n", 1);
}
