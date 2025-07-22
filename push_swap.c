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

#include "push_swap.h" //header

/// @brief divides & validates received args from terminal
/// @param argc num of args recived
/// @param argv array of args received
/// @param total_nums total num of digits stored in array - array[a][j]
/// @param n_array total num of splitted args - array[a]
/// @return triple char * w divided num
char	***ft_parse_arguments(int argc, char **argv, int *ttl_num, int *n_arr)
{
	char	***array;
	int		i;
	int		a;
	int		j;

	i = 1;
	a = 0;
	array = malloc(sizeof(char **) * (argc - 1));
	if (!array)
		return (NULL);
	*ttl_num = 0;
	while (argv[i] && ft_val_let(argv[i]))
	{
		array[a] = ft_split(argv[i], ' ');
		j = 0;
		while (array[a][j++])
			(*ttl_num)++;
		i++;
		a++;
	}
	*n_arr = a;
	return (array);
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
	int		*num;
	int		total_nums;
	int		n_array;

	total_nums = 0;
	n_array = 0;
	if (argc <= 1)
		return (0);
	array = ft_parse_arguments(argc, argv, &total_nums, &n_array);
	if (!array)
		return (0);
	num = ft_convert_to_int_array(array, n_array, total_nums);
	if (!num)
		return (0);
	if (!ft_val_num(num, total_nums))
		ft_out();
	if (!ft_is_sorted(num, total_nums))
		ft_algorithm_sel(num, total_nums);
	ft_free_array(array, n_array);
	free(num);
	return (0);
}
