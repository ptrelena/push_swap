/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:07 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:07 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena.c.perez <elena.c.perez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:33:10 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/15 13:37:56 by elena.c.per      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief moves stack's last element to top
/// @param stack ** to stack
void	ft_reverse_rotate(t_listps **stack)
{
	t_listps	*last; //* to last node
	t_listps	*second_to_last; //* to second-to-last node

	//nothing to do if no stack / empty stack / no node to rotate for
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second_to_last = *stack; //loop from start
	//loop until second-to-last node is reached
	while (second_to_last->next->next != NULL)
		second_to_last = second_to_last->next;
	last = second_to_last->next; //last is now following second-to-last
	second_to_last->next = NULL; //disconnect old second-to-last->next node
	last->next = *stack; //initial first node is now second node
	*stack = last; //last is now first node
}

/// @brief moves stack_a's last element to top
/// @param stack_a ** to stack_a
void	ft_rra(t_listps **stack_a)
{
	ft_reverse_rotate (stack_a); //reverse rotate a
	ft_printf ("rra\n"); //newline
}

/// @brief moves stack_b's last element to top
/// @param stack_b ** to stack_b
void	ft_rrb(t_listps **stack_b)
{
	ft_reverse_rotate (stack_b); //reverse rotate b
	ft_printf ("rrb\n"); //newline
}

/// @brief moves both stack_a & stack_b's last element to top
/// @param stack_a ** to stack_a
/// @param stack_b ** to stack_b
void	ft_rrr(t_listps **stack_a, t_listps **stack_b)
{
	ft_reverse_rotate (stack_a); //reverse rotate a & b
	ft_reverse_rotate (stack_b);
	ft_printf ("rrr\n"); //newline
}
