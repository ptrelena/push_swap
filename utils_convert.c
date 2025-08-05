/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:38 by elenpere          #+#    #+#             */
/*   Updated: 2025/08/04 19:52:10 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief converts str to long
/// @param nptr str to convert
/// @return converted str if ft_limt validation ok
int	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str [i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	ft_limit (sign * num);
	return (sign * num);
}

/// @brief converts ***char array to int array w validation
/// @param array ***char splitted array
/// @param n_array total num of splitted args - array[a]
/// @param total_nums total num of digits stored in array - array[a][j]
/// @return *int array w all values converted
int	*ft_convert_to_int_array(char ***array, int n_array, int total_nums)
{
	int	*nums;
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	nums = malloc(sizeof(int) * total_nums);
	if (!nums)
		return (NULL);
	while (i < n_array)
	{
		j = 0;
		while (array[i] && array[i][j])
		{
			if (array[i][j][0] == '\0')
			{
				free(nums);
				return (NULL);
			}
			nums[a++] = ft_atol(array[i][j++]);
		}
		i++;
	}
	return (nums);
}
