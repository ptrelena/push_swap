/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:35 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:53 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief adds new node to end of linked list
/// @param lst ** to first node of linked list
/// @param new node to be added
void	ft_lstadd_back_ps(t_listps **lst, t_listps *new)
{
	t_listps	*last;

	last = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

/// @brief adds new node to linked list beginning
/// @param lst ** to first node of linked list
/// @param new node to be added
void	ft_lstadd_front_ps(t_listps **lst, t_listps *new)
{
	new->next = *lst;
	*lst = new;
}

/// @brief finds linked list's last node
/// @param lst * to first node of linked list
/// @return * to last node / NULL if list is empty
t_listps	*ft_lstlast_ps(t_listps *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/// @brief calculates list size (num of nodes)
/// @param stack * to first node of linked list
/// @return num of nodes in linked list
int	ft_list_size_ps(t_listps *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

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
