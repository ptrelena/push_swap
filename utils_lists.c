/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:35 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:35 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief adds new node to end of linked list
/// @param lst ** to first node of linked list
/// @param new node to be added
void	ft_lstadd_back(t_listps **lst, t_listps *new)
{
	t_listps	*last; //aux node to work with

	last = *lst; //equal aux * to original
	if (!lst || !new) //if no list/no new node, nothing to do
		return ;
	if (*lst == NULL) //if list empty
	{
		*lst = new; //equal first node to new node
		return ;
	}
	while (last->next != NULL) //loop till last node reached
		last = last->next;
	last->next = new; //equal new node to node follwing last node
}

/// @brief adds new node to linked list beginning
/// @param lst ** to first node of linked list
/// @param new node to be added
void	ft_lstadd_front(t_listps **lst, t_listps *new)
{
	new->next = *lst; //new node pointing to initial first node
	*lst = new; //list beginning now pointing to new node
}

/// @brief finds linked list's last node
/// @param lst * to first node of linked list
/// @return * to last node / NULL if list is empty
t_listps	*ft_lstlast(t_listps *lst)
{
	if (lst == NULL) //return NULL if list is emty
		return (NULL);
	while (lst->next != NULL) //loop until NULL is reached
		lst = lst->next;
	return (lst); //return last node found
}

/// @brief creates new node alone for a future linked list
/// @param content value to store in new node
/// @return * to new node / NULL if mem allocation fails
t_listps	*ft_lstnew(int content)
{
	t_listps	*new;

	new = (t_listps *)malloc(sizeof (t_listps)); //mem allocation for node alone
	if (new == NULL) //allocation check
		return (NULL);
	new->content = content; //assign content argument to new node content
	new->key = 0; //initialize key for future value assignment
	new->next = NULL; //new node points to NULL
	return (new); //return new node
}

/// @brief calculates list size (num of nodes)
/// @param stack * to first node of linked list
/// @return num of nodes in linked list
int	ft_list_size(t_listps *stack)
{
	int	size; //counter

	size = 0;
	while (stack) //loop until end is reached
	{
		stack = stack->next;
		size++; //add up as a new node is found
	}
	return (size); //return size-num of nodes
}