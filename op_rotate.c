/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:10 by elenpere          #+#    #+#             */
/*   Updated: 2025/08/04 19:48:09 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief moves stack's first element to end
/// @param stack ** to stack
void	ft_rotate(t_listps **stack)
{
	t_listps	*final;
	t_listps	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	final = ft_lstlast_ps (*stack);
	final->next = first;
}

/// @brief moves stack_a's first element to end
/// @param stack_a ** to stack_a
void	ft_ra(t_listps **stack_a)
{
	ft_rotate (stack_a);
	ft_printf ("ra\n");
}

/// @brief moves stack_b's first element to end
/// @param stack_b ** to stack_b
void	ft_rb(t_listps **stack_b)
{
	ft_rotate (stack_b);
	ft_printf ("rb\n");
}

/// @brief moves both stack_a & stack_b's first element to end
/// @param stack_a ** to stack_a
/// @param stack_b ** to stack_b
void	ft_rr(t_listps **stack_a, t_listps **stack_b)
{
	ft_rotate (stack_a);
	ft_rotate (stack_b);
	ft_printf ("rr\n");
}
