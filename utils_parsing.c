/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/29 00:00:00 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief validates and counts numbers in a split array
/// @param array_elem single split array element
/// @return number of valid elements found
int	ft_validate_split_array(char **array_elem)
{
	int	j;

	if (!array_elem)
		ft_out();
	j = 0;
	while (array_elem[j])
	{
		if (array_elem[j][0] == '\0')
			ft_out();
		j++;
	}
	if (j == 0)
		ft_out();
	return (j);
}

/// @brief processes a single argument and adds to array
/// @param argv_elem argument to process
/// @param array main array to store results
/// @param a current array index
/// @return number of elements added
int	ft_process_argument(char *argv_elem, char ***array, int a)
{
	array[a] = ft_split(argv_elem, ' ');
	return (ft_validate_split_array(array[a]));
}

/// @brief handles error cleanup and exit
/// @param array array to free
/// @param num nums array to free
/// @param n_array number of arrays
int	ft_handle_error(char ***array, int *num, int n_array)
{
	if (array)
		ft_free_array(array, n_array);
	if (num)
		free(num);
	return (1);
}

/// @brief validates character by character in string
/// @param str string to validate
/// @param i current index
/// @param has_digit pointer to digit flag
static void	ft_validate_char(char *str, int i, int *has_digit)
{
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 32 || str[i] == 9
			|| str[i] == '-' || str[i] == '+'))
		ft_out();
	if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0'
			&& str[i + 1] <= '9'))
		ft_out();
	if ((str[i] >= '0' && str[i] <= '9'))
	{
		*has_digit = 1; //set digit flag
		if (!((str[i + 1] >= '0' && str[i + 1] <= '9')
			|| str[i + 1] == 32
			|| str[i + 1] == 9 || str[i + 1] == '\0'))
			ft_out();
	}
}

/// @brief validates str contains only allowed chars (digits, spaces, signs)
/// @param str arg to validate
/// @return valid returns 1, exits calling ft_out otherwise
int	ft_val_let(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (!str || str[0] == '\0')
		ft_out();
	while (str[i])
	{
		ft_validate_char(str, i, &has_digit);
		i++;
	}
	if (!has_digit)
		ft_out();
	return (1);
}
