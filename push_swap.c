/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:49:48 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 17:05:17 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief divides & validates received args from terminal
/// @param argc num of args recived
/// @param argv array of args received
/// @param ttl_num total num of digits stored in array - array[a][j]
/// @param n_arr total num of splitted args - array[a]
/// @return triple char * w divided num
char	***ft_parse_arguments(int argc, char **argv, int *ttl_num, int *n_arr)
{
	char	***array;
	int		i;
	int		a;

	i = 1;
	a = 0;
	array = malloc(sizeof(char **) * (argc - 1));
	if (!array)
		return (NULL);
	*ttl_num = 0;
	while (argv[i] && ft_str_val(argv[i]))
	{
		*ttl_num += ft_split_argument(argv[i], array, a);
		i++;
		a++;
	}
	*n_arr = a;
	return (array);
}

/// @brief processes parsed arguments and executes sorting
/// @param array parsed arguments
/// @param total_nums total number count
/// @param n_array array count
/// @return exit code
static int	ft_process_numbers(char ***array, int total_nums, int n_array)
{
	int	*num;

	num = ft_convert_to_int_array(array, n_array, total_nums);
	if (!num)
		return (ft_handle_error(array, NULL, n_array));
	if (total_nums == 0)
		return (ft_handle_error(array, num, n_array));
	if (!ft_find_duplicates(num, total_nums))
		ft_out();
	if (!ft_is_sorted(num, total_nums))
		ft_algorithm_sel(num, total_nums);
	ft_free_array(array, n_array);
	free(num);
	return (0);
}

/// @brief apply algorythm according to nums received
/// @param num int* including received nums to be sorted
/// @param total_nums total nums received
void	ft_algorithm_sel(int *num, int total_nums)
{
	t_listps	*stack_a;
	t_listps	*stack_b;

	stack_a = ft_create_lists(num, total_nums);
	stack_b = NULL;
	ft_assign_index (stack_a, total_nums);
	if (total_nums > 1 && total_nums <= 5)
		ft_sort_small (&stack_a, &stack_b, total_nums);
	if (total_nums >= 6)
		ft_sort_chunk (&stack_a, &stack_b, total_nums);
	ft_free_list (stack_a);
	ft_free_list (stack_b);
}

/// @brief push_swap sort nums
/// @param argc num of args recived
/// @param argv array of args received
/// @return sorted list of nums received
int	main(int argc, char **argv)
{
	char	***array;
	int		total_nums;
	int		n_array;

	total_nums = 0;
	n_array = 0;
	if (argc <= 1)
		return (1);
	array = ft_parse_arguments(argc, argv, &total_nums, &n_array);
	if (!array)
		return (1);
	return (ft_process_numbers(array, total_nums, n_array));
}
