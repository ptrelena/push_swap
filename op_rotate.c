/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:10 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:10 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena.c.perez <elena.c.perez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:33:10 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/15 13:37:57 by elena.c.per      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief moves stack's first element to end
/// @param stack ** to stack
void	ft_rotate(t_listps **stack)
{
	t_listps	*final;
	t_listps	*first;

	//nothing to do if no stack / empty stack / no node to rotate for
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack; //save stack's first node
	*stack = first->next; //initial first is now second node
	first->next = NULL; //disconect from first position
	final = ft_lstlast (*stack); //find final node
	final->next = first; //move initial first to end
}

/// @brief moves stack_a's first element to end
/// @param stack_a ** to stack_a
void	ft_ra(t_listps **stack_a)
{
	ft_rotate (stack_a); //rotate a
	ft_printf ("ra\n"); //newline
}

/// @brief moves stack_b's first element to end
/// @param stack_b ** to stack_b
void	ft_rb(t_listps **stack_b)
{
	ft_rotate (stack_b); //rotate b
	ft_printf ("rb\n"); //newline
}

/// @brief moves both stack_a & stack_b's first element to end
/// @param stack_a ** to stack_a
/// @param stack_b ** to stack_b
void	ft_rr(t_listps **stack_a, t_listps **stack_b)
{
	ft_rotate (stack_a); //rotate a
	ft_rotate (stack_b); //rotate b
	ft_printf ("rr\n"); //newline
}
