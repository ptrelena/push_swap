/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:00 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:00 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief sort stacks 2-5 elements
/// @param stack_a * stack_a
/// @param stack_b * stack_b
/// @param total_nums total nums in stack_a
void	ft_sort_small(t_listps **stack_a, t_listps **stack_b, int total_nums)
{
	int	first; //first element in stack_a
	int	second; //second element in stack_a

	first = (*stack_a)->content; //assign first's content
	second = (*stack_a)->next->content; //assign second's content
	if (total_nums == 2 && (first > second)) //2 num & first largest
		ft_sa(stack_a); //swap one another
	if (total_nums == 3) //3 num
		ft_sort_small_3 (stack_a, stack_b);
	if (total_nums == 4) //4 num
		ft_sort_small_4 (stack_a, stack_b);
	if (total_nums == 5) //5 mum
		ft_sort_small_5 (stack_a, stack_b);
}

/// @brief sort 3 element stack
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_sort_small_3(t_listps **stack_a, t_listps **stack_b)
{
	int	first; //first element in stack_a
	int	second; //second element in stack_a
	int	third; //third element in stack_a

	first = (*stack_a)->content; //assign first's content
	second = (*stack_a)->next->content; //assign second's content
	third = (*stack_a)->next->next->content; //assign third's content
	if ((first > second) && (second > third)) //[4, 3, 2]
	{
		ft_sa (stack_a); //swap two first elements [3, 4, 2]
		ft_rra (stack_a); //move last to top [2, 3, 4]
	}
	if ((first > third) && (third > second)) //[4, 2, 3]
		ft_ra (stack_a); //move first to bottom [2, 3, 4]
	if ((second > first) && (first > third)) //[3, 4, 2]
		ft_rra (stack_a); //move last to top [2, 3, 4]
	if ((second > third) && (third > first)) //[2, 4, 3]
	{
		ft_sa (stack_a); //swap two first elements [4, 2, 3]
		ft_ra (stack_a); //move first to bottom [2, 3, 4]
	}
	if ((third > first) && (first > second)) //[3, 2, 4]
		ft_sa(stack_a); //swap two first elements [2, 3, 4]
}

/// @brief sort 4 element stack
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_sort_small_4(t_listps **stack_a, t_listps **stack_b)
{
	while ((*stack_a)->key != 0) //loop until key == 0
		ft_ra(stack_a); //rotate to get smallest element on top
	ft_pb(stack_a, stack_b); //push stacks_a's smallest element to stack_b
	ft_sort_small_3(stack_a, stack_b); //sort remaining 3 in stack_a
	ft_pa(stack_a, stack_b); //push smallest element back to stack_a
}

/// @brief sort 5 element stack
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_sort_small_5(t_listps **stack_a, t_listps **stack_b)
{
	int	i; //counter for elements pushed to stack_b

	i = 0;
	while (i < 2) //loop until 3 elements only on stack_a
	{
		if ((*stack_a)->key == 0 || (*stack_a)->key == 1) //find two smallest num
		{
			ft_pb (stack_a, stack_b); //push both nums to stack_b
			i++;
		}
		else
			ft_ra (stack_a); //rotate to get to smallest nums on top
	}
	if ((*stack_b)->key < (*stack_b)->next->key) //sort nums in stack_b
		ft_sb (stack_a); //swap if first is smaller than second
	ft_sort_small_3(stack_a, stack_b); //sort remaning 3 in stack_a
	ft_pa (stack_a, stack_b); //push second smallest from stack_b to stack_a
	ft_pa (stack_a, stack_b); //push smallest from stack_b to stack_a
}
