/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:28 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:28 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief frees linked list mem
/// @param stack * head of list
void	ft_free_list(t_listps *stack)
{
	t_listps	*tmp; //temp pointer

	while (stack) //loop until end of list
	{
		tmp = stack; //save current node
		stack = stack->next; //move to next node
		free(tmp); //free current node
	}
}

/// @brief frees triple char array
/// @param array triple char array to be freed
/// @param n_arrays num of subarrays in array
void	ft_free_array(char ***array, int n_arrays)
{
	int	i; //subarrays loop
	int	j; //subarrays' str loop

	i = 0;
	while (i < n_arrays) //loop until final subarray
	{
		j = 0;
		while (array[i][j]) //loop until final str end
			ft_free(array[i][j++]); //free str
		ft_free(array[i]); //free subarray
		i++; //keep looping
	}
	ft_free(array); //free triple array
}

/// @brief exit program
/// @param void
void	ft_out(void)
{
	ft_printf("Error\n"); //print error message
	exit(1); //exit through error stdout
}

