/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:31 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:31 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
BUBBLE SORT ALGORYTHM
Bubble Sort funciona bien con arrays porque su estructura permite acceder y comparar rápidamente elementos contiguos.
1. Acceso por índice inmediato:
	.En un array puedes acceder a cualquier elemento con arr[i], lo cual es muy eficiente.
	.Bubble Sort necesita comparar elementos adyacentes muchas veces: arr[i] con arr[i+1], lo cual es rápido en arrays.

2. Simplicidad:
	.Es muy fácil de implementar y suficiente para ordenar un array pequeño, como el que se usa para asignar índices en push_swap.
	.No lo usas para ordenar la pila real:
	.Solo lo usas para obtener una versión ordenada de los valores y así calcular los ranks o posiciones relativas de cada número.
	.En ese caso no necesitas eficiencia máxima, sino algo simple y funcional.
*/

/// @brief Bubble Sort algorythm
/// @param array int array to be sorted
/// @param total_nums total num of ints in array
/// @return sorted array
int	*ft_array_index(int *array, int total_nums)
{
	int	temp; //temp for swapping
	int	i; //loop between array nodes (array[i])
	int	j; //loop inside array nodes (array[i])

	temp = 0;
	i = 0;
	j = 0;
	while (i < total_nums - 1) //loop until i reaches second-to-last
	{
		j = 0; //initialized every loop to 0
		while (j < total_nums - 1) //loop until i reaches second-to-last
		{
			if (array[j] > array[j + 1]) //if current node > following node, swap
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++; //keep looping
		}
		i++;
	}
	return (array); //return sorted array
}

/// @brief assign keys to sorted int array
/// @param stack * to head of linked list from terminal
/// @param array already sorted int array
/// @param total_nums num of int in array
void	ft_assign_keys(t_listps *stack, int *array, int total_nums)
{
	int	i;

	while (stack) //stack exists
	{
		i = 0; //reset every loop
		while (i < total_nums) //until i reached end of nums
		{
			if (array[i] == stack->content) //if equal
			{
				stack->key = i; //int index = key to later sort linked list
				break ; //break to change to following node
			}
			i++; //keep looping until equal node & array int
		}
		stack = stack->next; //loop to next node
	}
}

/// @brief assigns index to nodes
/// @param stack * to head of linked list from terminal
/// @param total_nums num of nodes in linked list
void	ft_assign_index(t_listps *stack, int total_nums)
{
	t_listps	*tmp; //temp *
	int			*array; //array to store node contents
	int			i; //counter for array

	i = 0;
	tmp = stack; //equal temp to original stack
	array = malloc(sizeof(int) * total_nums); //mem allocation for array
	if (!array) //allocation check
		return ;
	while (tmp) //stack exists
	{
		array[i] = tmp->content; //store node content in array
		tmp = tmp->next; //loop to next node
		i++; //loop to next element in array
	}
	i = 0; //reset array counter for index allocation
	array = ft_array_index(array, total_nums); //sort array
	ft_assign_keys(stack, array, total_nums); //assign keys to nodes
	free(array); //free allocated mem for array
}

/// @brief check if int array is sorted in ascending order
/// @param nums int array
/// @param total_nums nums of int in array
/// @return 1 if sorted, 0 otherwise
int	ft_is_sorted(int *nums, int total_nums)
{
	int	i; //counter for array

	i = 0;
	while (i < total_nums - 1) //loop until second-to-last is reached
	{
		if (nums[i] > nums[i + 1]) //if current node > following node exit program
			return (0);
		i++; //keep looping
	}
	//	last node is not directly analyzed, but it is compared in if (nums[i] > nums[i + 1])
	//	when analyzing second-to-last node(nums[i]), if > last node(nums[i + 1]) we return 0
	//	only here is last node analyzed undirectly
	return (1); //list is sorted then return 1
}
