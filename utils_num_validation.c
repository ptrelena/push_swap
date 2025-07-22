/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:38 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 17:08:16 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief validates str contains only allowed chars (digits, spaces, signs)
/// @param str arg to validate
/// @return valid returns 1, exits calling ft_out otherwise
int	ft_val_let(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 32 || str[i] == 9
				|| str[i] == '-' || str[i] == '+'))
			ft_out();
		if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0'
				&& str[i + 1] <= '9'))
			ft_out();
		if ((str[i] >= '0' && str[i] <= '9')
			&& !((str[i + 1] >= '0' && str[i + 1] <= '9')
				|| str[i + 1] == 32
				|| str[i + 1] == 9 || str[i + 1] == '\0'))
			ft_out();
		i++;
	}
	return (1);
}

/// @brief checks for duplicate nums in array
/// @param nums nums in array
/// @param size total of nums in array
/// @return 1 if unique values, 0 if duplicate
int	ft_val_num(int *nums, int size)
{
	int	i;
	int	a;

	i = 0;
	while (i < size)
	{
		a = 0;
		while (a < i)
		{
			if (nums[a] == nums[i])
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

/// @brief checks if nun if within INT_MIN & INT_MAX
/// @param num long int to validate
/// @return 1 if valid, exits program otherwise
int	ft_limit(long num)
{
	long	temp;

	temp = num;
	if (temp < INT_MIN || temp > INT_MAX)
		ft_out();
	return (1);
}

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
			nums[a] = ft_atol(array[i][j]);
			a++;
			j++;
		}
		i++;
	}
	return (nums);
}
