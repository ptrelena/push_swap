/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:33:10 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 16:35:31 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief moves stack's last element to top
/// @param stack ** to stack
void	ft_reverse_rotate(t_listps **stack)
{
	t_listps	*last;
	t_listps	*second_to_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second_to_last = *stack;
	while (second_to_last->next->next != NULL)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/// @brief moves stack_a's last element to top
/// @param stack_a ** to stack_a
void	ft_rra(t_listps **stack_a)
{
	ft_reverse_rotate (stack_a);
	ft_printf ("rra\n");
}

/// @brief moves stack_b's last element to top
/// @param stack_b ** to stack_b
void	ft_rrb(t_listps **stack_b)
{
	ft_reverse_rotate (stack_b);
	ft_printf ("rrb\n");
}

/// @brief moves both stack_a & stack_b's last element to top
/// @param stack_a ** to stack_a
/// @param stack_b ** to stack_b
void	ft_rrr(t_listps **stack_a, t_listps **stack_b)
{
	ft_reverse_rotate (stack_a);
	ft_reverse_rotate (stack_b);
	ft_printf ("rrr\n");
}
