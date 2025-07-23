/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:49:54 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:20 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief sort stack Chunk algorythm
/// @param stack_a * stack_a
/// @param stack_b * stack_b
/// @param size total num of elements in stack_a
void	ft_sort_chunk(t_listps **stack_a, t_listps **stack_b, int size)
{
	ft_assign_index (*stack_a, size);
	ft_push_chunk_b (stack_a, stack_b, size);
	ft_push_back (stack_a, stack_b);
}

/// @brief push elements from stack_a to stack_b in chunks
/// @param stack_a * stack_a
/// @param stack_b * stack_b
/// @param size total num of elements in stack_a
void	ft_push_chunk_b(t_listps **stack_a, t_listps **stack_b, int size)
{
	int	chunk;
	int	push;
	int	i;

	if (size <= 100)
		chunk = 20;
	else
		chunk = 53;
	push = 0;
	i = chunk;
	while (push < size)
	{
		if ((*stack_a)->key < i)
		{
			ft_pb (stack_a, stack_b);
			push++;
			if ((*stack_b)->key < i - (chunk / 2))
				ft_rb (stack_b);
		}
		else
			ft_ra (stack_a);
		if (push >= i)
			i = i + chunk;
	}
}

/// @brief finds largest element position in stack
/// @param stack * to stack
/// @return largest element position
int	ft_find_max_pos(t_listps *stack)
{
	t_listps	*temp;
	int			max;
	int			pos;
	int			i;

	max = stack->key;
	pos = 0;
	i = 0;
	temp = stack;
	while (temp)
	{
		if (temp->key > max)
		{
			max = temp->key;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

/// @brief pushing sorted list back to stack_a from stack_b
/// @param stack_a * stack_a
/// @param stack_b * stack_b
void	ft_push_back(t_listps **stack_a, t_listps **stack_b)
{
	int	max_pos;
	int	size_b;

	while (*stack_b)
	{
		max_pos = ft_find_max_pos (*stack_b);
		size_b = ft_list_size_ps (*stack_b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos > 0)
			{
				ft_rb (stack_b);
				max_pos--;
			}
		}
		else
		{
			while (++max_pos < size_b)
				ft_rrb (stack_b);
		}
		ft_pa (stack_a, stack_b);
	}
}
