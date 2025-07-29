/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:19 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 16:37:19 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief swaps first two elements of stack
/// @param stack ** to stack
void	ft_swap(t_listps **stack)
{
	int	temp_content;
	int	temp_key;


	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp_content = (*stack)->content;
	temp_key = (*stack)->key;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp_content;
	(*stack)->key = (*stack)->next->key;
	(*stack)->next->key = temp_key;
}

/// @brief swaps first two elements of stack_a
/// @param stack_a ** to stack_a
void	ft_sa(t_listps **stack_a)
{
	ft_swap (stack_a);
	ft_printf ("sa\n");
}

/// @brief swaps first two elements of stack_b
/// @param stack_b ** to stack_b
void	ft_sb(t_listps **stack_b)
{
	ft_swap (stack_b);
	ft_printf ("sb\n");
}

/// @brief swaps first two elements of both stack_a & stack_b
/// @param stack_a ** to stack_a
/// @param stack_b ** to stack_b
void	ft_ss(t_listps **stack_a, t_listps **stack_b)
{
	ft_swap (stack_a);
	ft_swap (stack_b);
	ft_printf ("ss\n");
}
