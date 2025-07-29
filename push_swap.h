/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:50:23 by elenpere          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:22 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_listps
{
	struct s_listps	*next;
	int				content;
	int				key;
}	t_listps;

char			***ft_parse_arguments(int argc, char **argv,
					int *nums, int *n_arr);
t_listps		*ft_create_lists(int *nums, int total_nums);
t_listps		*ft_lstlast_ps(t_listps *lst);
t_listps		*ft_lstnew_ps(int content);
int				*ft_convert_to_int_array(char ***array,
					int n_arrays, int total_nums);
int				ft_limit(long num);
int				ft_val_num(int *nums, int size);
int				ft_val_let(char *str);
int				ft_atol(const char *nptr);
int				ft_is_sorted(int *nums, int total_nums);
int				*ft_array_index(int *array, int total_nums);
int				ft_find_max_pos(t_listps *stack);
int				ft_list_size_ps(t_listps *stack);
void			ft_algorithm_sel(int *num, int total_nums);
void			ft_free_array(char ***array, int n_arrays);
void			ft_lstadd_back_ps(t_listps **lst, t_listps *new);
void			ft_lstadd_front_ps(t_listps **lst, t_listps *new);
void			ft_free_list(t_listps *stack);
void			ft_out(void);
void			ft_push(t_listps **dest, t_listps **origin);
void			ft_pa(t_listps **stack_a, t_listps **stack_b);
void			ft_pb(t_listps **stack_a, t_listps **stack_b);
void			ft_reverse_rotate(t_listps **stack);
void			ft_rra(t_listps **stack_a);
void			ft_rrb(t_listps **stack_b);
void			ft_rrr(t_listps **stack_a, t_listps **stack_b);
void			ft_rotate(t_listps **stack);
void			ft_ra(t_listps **stack_a);
void			ft_rb(t_listps **stack_b);
void			ft_rr(t_listps **stack_a, t_listps **stack_b);
void			ft_swap(t_listps **stack);
void			ft_sa(t_listps **stack_a);
void			ft_sb(t_listps **stack_b);
void			ft_ss(t_listps **stack_a, t_listps **stack_b);
void			ft_sort_small(t_listps **stack_a, t_listps **stack_b,
					int total_nums);
void			ft_sort_small_3(t_listps **stack_a);
void			ft_sort_small_4(t_listps **stack_a, t_listps **stack_b);
void			ft_sort_small_5(t_listps **stack_a, t_listps **stack_b);
void			ft_assign_keys(t_listps *stack, int *array, int total_nums);
void			ft_assign_index(t_listps *stack, int total_nums);
void			ft_sort_chunk(t_listps **stack_a, t_listps **stack_b, int size);
void			ft_push_chunk_b(t_listps **stack_a, t_listps **stack_b,
					int size);
void			ft_push_back(t_listps **stack_a, t_listps **stack_b);
int				ft_validate_split_array(char **array_elem);
int				ft_process_argument(char *argv_elem, char ***array, int a);
int				ft_handle_error(char ***array, int *num, int n_array);

#endif
