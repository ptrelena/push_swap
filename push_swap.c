/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 09:49:48 by elenpere          #+#    #+#             */
/*   Updated: 2025-07-18 09:49:48 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" //header

/// @brief divides & validates received args from terminal
/// @param argc num of args recived
/// @param argv array of args received
/// @param total_nums total num of digits stored in array - array[a][j]
/// @param n_array total num of splitted args - array[a]
/// @return triple char * w divided num
char	***ft_parse_arguments(int argc, char **argv, int *total_nums, int *n_array)
{
	char	***array; //triple char* to store splitted args
	int		i; //index to loop argv
	int		a; //index to fill array[a] (n_array)
	int		j; //index to count subargs array[a][j] (total )

	i = 1; //starting in 1 to skip program name (executable file)
	a = 0; //starts in first arg filling splitted array
	array = malloc(sizeof(char **) * (argc - 1)); //allocate mem for ***char array
	if (!array) //allocation check
		return (NULL);
	*total_nums = 0; //starting digits in 0
	while (argv[i] && ft_val_let(argv[i])) //argv[1] exists && parsing ok
	{
		array[a] = ft_split(argv[i], ' '); //split args to char array
		j = 0; //start from first subarg array[a][j]
		while (array[a][j++]) //while digits exist
			(*total_nums)++; //add up digit found
		i++; //loop to next argv received
		a++; //loop to next array[a]
	}
	*n_array = a; //index a = number of args stored in char* array
	return (array); //return final char *array
}

/// @brief apply algorythm according to nums received
/// @param num int* including received nums to be sorted
/// @param total_nums total nums received
void	ft_algorithm_sel(int *num, int total_nums)
{
	t_listps	*stack_a; //* to stack a			
	t_listps	*stack_b; //* to stack b

	stack_a = ft_create_lists(num, total_nums); //int array converted to linked list
	stack_b = NULL; //stack b initially empty
	ft_assign_index (stack_a, total_nums); //assign sorted 'key' value
	if (total_nums > 1 && total_nums <= 5) //no more than 5 num received
		ft_sort_small (&stack_a, &stack_b, total_nums); //apply small algorythm
	if (total_nums >= 6) //more than 5 num received
		ft_sort_chunk (&stack_a, &stack_b, total_nums); //apply chunk algorythm
	ft_free_list (stack_a); //free mem
	ft_free_list (stack_b); //free mem
}/// @brief push_swap sort nums
/// @param argc num of args recived
/// @param argv array of args received
/// @return sorted list of nums received
int	main(int argc, char **argv)
{
	char	***array; //save nums individually as str
	int		*num; //final int array
	int		total_nums; //total nums
	int		n_array; //split arrays, one for each received arg			

	total_nums = 0;
	n_array = 0;
	if (argc <= 1) //if no args program ends
		return (0);
	array = ft_parse_arguments(argc, argv, &total_nums, &n_array); //num parsing
	if (!array) //allocation check
		return (0);
	num = ft_convert_to_int_array(array, n_array, total_nums);
	if (!num)
		return (0);
	if (!ft_val_num(num, total_nums))
		ft_out();
	if (!ft_is_sorted(num, total_nums))
		ft_algorithm_sel(num, total_nums);
	ft_free_array(array, n_array);
	ft_free(num);
	return (0);
}
