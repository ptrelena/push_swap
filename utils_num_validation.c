/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:50:38 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:50:38 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief validates str contains only allowed chars (digits, spaces, signs)
/// @param str arg to validate
/// @return valid returns 1, exits calling ft_out otherwise
int	ft_val_let(char *str)
{
	int	i; //counter to loop str

	i = 0;
	while (str[i]) //while str exists
	{
		//str differetn from digit, space or sign
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 32 || str[i] == 9
				|| str[i] == '-' || str[i] == '+'))
			ft_out(); //exit
		//str equal to sign but not followed by a num
		if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0'
				&& str[i + 1] <= '9'))
			ft_out(); //exit
		//str is a num but not followed by digit, space or sign
		if ((str[i] >= '0' && str[i] <= '9')
			&& !((str[i + 1] >= '0' && str[i + 1] <= '9')
				|| str[i + 1] == 32
				|| str[i + 1] == 9 || str[i + 1] == '\0'))
			ft_out(); //exit
		i++; //loop to following char
	}
	return (1); //return 1 if str is valid
}

/// @brief checks for duplicate nums in array
/// @param nums nums in array
/// @param size total of nums in array
/// @return 1 if unique values, 0 if duplicate
int	ft_val_num(int *nums, int size)
{
	int	i; //counter 1
	int	a; //counter 2

	i = 0; //initiate 0 for first num
	while (i < size) //loop until i reached aray size
	{
		a = 0; //always restarted to analyze all 'a' to new 'i'
		while (a < i) //loop until a reaches i
		{
			if (nums[a] == nums[i]) //end program if equal
				return (0);
			a++;
		}
		i++;
	}
	return (1); //return 1 if no equal num found
}

/// @brief checks if nun if within INT_MIN & INT_MAX
/// @param num long int to validate
/// @return 1 if valid, exits program otherwise
int	ft_limit(long num)
{
	long	temp; //aux variable

	temp = num; //equals aux to original variable
	if (temp < INT_MIN || temp > INT_MAX) //num not within INT_MIN & INT_MAX
		ft_out(); //exit ft
	return (1); //returns 1 if num within INT_MIN & INT_MAX
}

/// @brief converts str to long
/// @param nptr str to convert
/// @return converted str if ft_limt validation ok
int	ft_atol(const char *str)
{
	long	num; //store final num
	int		i; //counter loop for str
	int		sign; //long sign

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ') //no spaces
		i++;
	if (str[i] == '+' || str [i] == '-') //define sign
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') //digits
	{
		num = 10 * num + (str[i] - '0'); //convert char digit to int digit
		i++;
	}
	ft_limit (sign * num); //check if num is within INT_MIN & INT_MAX
	return (sign * num); //return converted num
}

/// @brief converts ***char array to int array w validation
/// @param array ***char splitted array
/// @param n_array total num of splitted args - array[a]
/// @param total_nums total num of digits stored in array - array[a][j]
/// @return *int array w all values converted
int	*ft_convert_to_int_array(char ***array, int n_array, int total_nums)
{
	int	*nums; //final *int array
	int	i; //index to loop parsing array[a]
	int	j; //index to loop parsing array[a][j]
	int	a; //index to fill nums[a]

	i = 0;
	a = 0;
	nums = malloc(sizeof(int) * total_nums); //allocate mem for *int array
	if (!nums) //allocation check
		return (NULL);
	while (i < n_array) //loop until i reached last number in array
	{
		j = 0; //always initialized as loops from n_array start
		while (array[i] && array[i][j]) //while both exist
		{
			nums[a] = ft_atol(array[i][j]); //fill nums[a] w array[i][j] int value
			//array[i][j] is a *char that points to total num passed to atol
			a++;
			j++;
		}
		i++;
	}
	return (nums); //return array w all values converted
}
