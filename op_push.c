/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:04 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 16:34:22 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief moves origin's top node to dest top
/// @param dest * to dest stack
/// @param origin * to origin stack
void	ft_push(t_listps **dest, t_listps **origin)
{
	t_listps	*tmp;

	if (!origin || !*origin)
		return ;
	tmp = *origin;
	*origin = (*origin)->next; //origin top is now second node
	tmp->next = NULL;
	ft_lstadd_front_ps (dest, tmp);
}

/// @brief push top element from stack_b to stack_a
/// @param stack_a * to stack_a
/// @param stack_b * to stack_b
void	ft_pa(t_listps **stack_a, t_listps **stack_b)
{
	ft_push (stack_a, stack_b);
	ft_printf ("pa\n");
}

/// @brief push top element from stack_a to stack_b
/// @param stack_a * to stack_a
/// @param stack_b * to stack_b
void	ft_pb(t_listps **stack_a, t_listps **stack_b)
{
	ft_push (stack_b, stack_a);
	ft_printf ("pb\n");
}
