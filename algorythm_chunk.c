/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:49:54 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:49:54 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
CHUNKS
El método de chunks es ideal para listas enlazadas en push_swap porque se adapta a las restricciones del proyecto y reduce la cantidad de movimientos necesarios, mientras que otros algoritmos clásicos no serían viables en esta estructura ni con estas limitaciones.
1. No hay acceso por índice:
	.En una lista enlazada, acceder a un elemento específico requiere recorrerla nodo por nodo.
	.Algoritmos como Bubble Sort, que hacen muchas comparaciones entre posiciones específicas, son muy lentos en listas enlazadas.

2. Limitación de operaciones en push_swap:
	.Solo puedes usar funciones como sa, pb, ra, etc. No puedes mover libremente por la lista como en un array.
	.El método de chunks está pensado para trabajar con estas operaciones permitidas, organizando la lista en pasos progresivos y eficientes.

3. Chunks = optimización de movimientos:
	.Divides el rango de valores en “chunks” (por ejemplo, de 20 en 20 si hay 100 elementos).
	.Vas empujando los valores del stack A al B por grupos, lo que permite planificar los ra y rra de forma inteligente.
	.Luego reconstruyes el stack ordenado desde B a A con el menor número de movimientos posible.
*/

/// @brief sort stack Chunk algorythm
/// @param stack_a * stack_a
/// @param stack_b * stack_b
/// @param size total num of elements in stack_a
void	ft_sort_chunk(t_listps **stack_a, t_listps **stack_b, int size)
{
	ft_assign_index (*stack_a, size); //assign index
	ft_push_chunk_b (stack_a, stack_b, size); //push elements to stack_b in chunks
	ft_push_back (stack_a, stack_b); //push sorted elements back to stack_a
}

/// @brief push elements from stack_a to stack_b in chunks
/// @param stack_a * stack_a
/// @param stack_b * stack_b
/// @param size total num of elements in stack_a
void	ft_push_chunk_b(t_listps **stack_a, t_listps **stack_b, int size)
{
	int	chunk; //size of each chunk
	int	push; //counter for pushed elements
	int	i; //chunk limit

	if (size <= 100) //define chunk in 20 if stack size <= 100
		chunk = 20;
	else //define chunk in 53 if larger than 100
		chunk = 53;
	push = 0; //initialize push counter
	i = chunk; //set initial chunk limit
	while (push < size) //push elements ultil all are moved
	{
		if ((*stack_a)->key < i) //check if element belongs to current chunk
		{
			ft_pb (stack_a, stack_b); //push to stack_b
			push++; //keep looping
			//	if pushed element < [20 - (20 / 2) = 10] means its a small num 
			//	convinient to have it at stack_b's bottom when pushing back to stack_a
			if ((*stack_b)->key < i - (chunk / 2))
				ft_rb (stack_b); //move to bottom
		}
		else //if element does not belong to chunk
			ft_ra (stack_a); //move to bottom
		if (push >= i) //chunk over
			i = i + chunk; //add up next chunk if available elements
	}
}

/// @brief finds largest element position in stack
/// @param stack * to stack
/// @return largest element position
int	ft_find_max_pos(t_listps *stack)
{
	t_listps	*temp; //temp for stack
	int			max; //largest value found
	int			pos; //largest value position
	int			i; //counter

	max = stack->key; //initiate from first key
	pos = 0;
	i = 0;
	temp = stack; //equal temp to original stack
	while (temp) //stack exists
	{
		if (temp->key > max) //if current element is larger than max
		{
			max = temp->key; //update max value
			pos = i; //position equal to index
		}
		temp = temp->next; //move to next element
		i++; //loop
	}
	return (pos); //return position to largest value
}

/// @brief pushing sorted list back to stack_a from stack_b
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_push_back(t_listps **stack_a, t_listps **stack_b)
{
	int	max_pos; //largest element position in stack_b
	int	size_b; //size of stack_b

	while (*stack_b) //stack_b exists
	{
		max_pos = ft_find_max_pos (*stack_b); //find largest value's pos
		size_b = ft_list_size (*stack_b); //define stack_b's size
		if (max_pos <= size_b / 2) //max_pos in stack_b's first half
		{
			while (max_pos > 0) //until max_pos reaches 1
			{
				ft_rb (stack_b); //rotate until max_pos element is on top
				max_pos--;
			}
		}
		else //max_pos in stack_b's second half
		{
			while (++max_pos < size_b) //until max_pos does not reach stack_b' size
				ft_rrb (stack_b); //reverse rotate until max_pos element is on top
		}
		ft_pa (stack_a, stack_b); //push top element to stack_a
	}
}


