/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:31 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 16:41:08 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Bubble Sort algorythm
/// @param array int array to be sorted
/// @param total_nums total num of ints in array
/// @return sorted array
int	*ft_bubble_sort(int *array, int total_nums)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = 0;
	j = 0;
	while (i < total_nums - 1)
	{
		j = 0;
		while (j < total_nums - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

/// @brief assign keys to sorted int array
/// @param stack * to head of linked list from terminal
/// @param array already sorted int array
/// @param total_nums num of int in array
void	ft_assign_keys(t_listps *stack, int *array, int total_nums)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < total_nums)
		{
			if (array[i] == stack->content)
			{
				stack->key = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

/// @brief assigns index to nodes
/// @param stack * to head of linked list from terminal
/// @param total_nums num of nodes in linked list
void	ft_assign_index(t_listps *stack, int total_nums)
{
	t_listps	*tmp;
	int			*array;
	int			i;

	i = 0;
	tmp = stack;
	array = malloc(sizeof(int) * total_nums);
	if (!array)
		return ;
	while (tmp)
	{
		array[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	array = ft_bubble_sort(array, total_nums);
	ft_assign_keys(stack, array, total_nums);
	free(array);
}

/// @brief check if int array is sorted in ascending order
/// @param nums int array
/// @param total_nums nums of int in array
/// @return 1 if sorted, 0 otherwise
int	ft_is_sorted(int *nums, int total_nums)
{
	int	i;

	i = 0;
	while (i < total_nums - 1)
	{
		if (nums[i] > nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}
