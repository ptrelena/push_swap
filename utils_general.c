/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:28 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:43 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief frees linked list mem
/// @param stack * head of list
void	ft_free_list(t_listps *stack)
{
	t_listps	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/// @brief frees triple char array
/// @param array triple char array to be freed
/// @param n_arrays num of subarrays in array
void	ft_free_array(char ***array, int n_arrays)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_arrays)
	{
		j = 0;
		while (array[i][j])
			free(array[i][j++]);
		free(array[i]);
		i++;
	}
	free(array);
}

/// @brief exit program
/// @param void
void	ft_out(void)
{
	ft_printf("Error\n");
	exit(1);
}
