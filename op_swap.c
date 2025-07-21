/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:19 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:19 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief swaps first two elements of stack
/// @param stack ** to stack
void	ft_swap(t_listps **stack)
{
	int	temp_content; //temp for content value
	int	temp_key; //temp for key value

	//nothing to do if no stack / empty stack / no value to swap for
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp_content = (*stack)->content; //save first node's content value in temp
	temp_key = (*stack)->key; //save first node's key value in temp
	(*stack)->content = (*stack)->next->content; //replace first node's content for sencond's
	(*stack)->next->content = temp_content; //assign second node's content value to temp content
	(*stack)->key = (*stack)->next->key; //replace first node's key for sencond's
	(*stack)->next->key = temp_key; //assign second node's key value to temp content
}

/// @brief swaps first two elements of stack_a
/// @param stack_a ** to stack_a
void	ft_sa(t_listps **stack_a)
{
	ft_swap (stack_a); //swap a
	ft_printf ("sa\n"); //newline
}

/// @brief swaps first two elements of stack_b
/// @param stack_b ** to stack_b
void	ft_sb(t_listps **stack_b)
{
	ft_swap (stack_b); //swap b
	ft_printf ("sb\n"); //newline
}

/// @brief swaps first two elements of both stack_a & stack_b
/// @param stack_a ** to stack_a
/// @param stack_b ** to stack_b
void	ft_ss(t_listps **stack_a, t_listps **stack_b)
{
	ft_swap (stack_a); //swap a
	ft_swap (stack_b); //swap b
	ft_printf ("ss\n"); //newline
}
