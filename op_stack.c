/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:15 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 16:36:33 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief creates linked list (stack) from int array
/// @param nums * array to be added to list
/// @param total_nums total num of ints
/// @return * to head of list / NULL if mem allocation fails
t_listps	*ft_create_lists(int *nums, int total_nums)
{
	t_listps	*stack;
	t_listps	*node;
	int			i;

	i = 0;
	stack = NULL;
	while (i < total_nums)
	{
		node = malloc(sizeof(t_listps));
		if (!node)
		{
			ft_free_list(stack);
			return (NULL);
		}
		node->content = nums[i];
		node->next = NULL;
		ft_lstadd_back_ps(&stack, node);
		i++;
	}
	return (stack);
}
