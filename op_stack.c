/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:15 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:15 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief creates linked list (stack) from int array
/// @param nums * array to be added to list
/// @param total_nums total num of ints
/// @return * to head of list / NULL if mem allocation fails
t_listps	*ft_create_lists(int *nums, int total_nums)
{
	t_listps	*stack; //* to head of list
	t_listps	*node; //* to node being created
	int			i; //loop for array

	i = 0;
	stack = NULL; //initiate list
	while (i < total_nums) //loop until last int is reached
	{
		node = malloc(sizeof(t_listps)); //mem allocation for new node
		if (!node) //allocation check
		{
			free_list(stack); //free list
			return (NULL); //failure
		}
		node->content = nums[i]; //assign node vale num[i] from int array
		node->next = NULL; //assign NULL as next node's value
		ft_lstadd_back(&stack, node); //add to node to end
		i++; //next num
	}
	return (stack); //return * pointing to final stack array's first node
}
