/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:00 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 16:33:26 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief sort stacks 2-5 elements
/// @param stack_a * stack_a
/// @param stack_b * stack_b
/// @param total_nums total nums in stack_a
void	ft_sort_small(t_listps **stack_a, t_listps **stack_b, int total_nums)
{
	int	first;
	int	second;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	if (total_nums == 2 && (first > second))
		ft_sa(stack_a);
	if (total_nums == 3)
		ft_sort_small_3 (stack_a);
	if (total_nums == 4)
		ft_sort_small_4 (stack_a, stack_b);
	if (total_nums == 5)
		ft_sort_small_5 (stack_a, stack_b);
}

/// @brief sort 3 element stack
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_sort_small_3(t_listps **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if ((first > second) && (second > third))
	{
		ft_sa (stack_a);
		ft_rra (stack_a);
	}
	if ((first > third) && (third > second))
		ft_ra (stack_a);
	if ((second > first) && (first > third))
		ft_rra (stack_a);
	if ((second > third) && (third > first))
	{
		ft_sa (stack_a);
		ft_ra (stack_a);
	}
	if ((third > first) && (first > second))
		ft_sa(stack_a);
}

/// @brief sort 4 element stack
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_sort_small_4(t_listps **stack_a, t_listps **stack_b)
{
	while ((*stack_a)->key != 0)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_small_3(stack_a);
	ft_pa(stack_a, stack_b);
}

/// @brief sort 5 element stack
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_sort_small_5(t_listps **stack_a, t_listps **stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*stack_a)->key == 0 || (*stack_a)->key == 1)
		{
			ft_pb (stack_a, stack_b);
			i++;
		}
		else
			ft_ra (stack_a);
	}
	if ((*stack_b)->key < (*stack_b)->next->key)
		ft_sb (stack_b);
	ft_sort_small_3(stack_a);
	ft_pa (stack_a, stack_b);
	ft_pa (stack_a, stack_b);
}
