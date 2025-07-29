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
		*lst = new; //equal first node to new node
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
	*lst = new; //list beginning now pointing to new node
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

/// @brief creates new node alone for a future linked list
/// @param content value to store in new node
/// @return * to new node / NULL if mem allocation fails
t_listps	*ft_lstnew_ps(int content)
{
	t_listps	*new;

	new = (t_listps *)malloc(sizeof (t_listps));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->key = 0;
	new->next = NULL;
	return (new);
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
