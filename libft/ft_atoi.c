/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:03:56 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 16:03:56 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief coverts from char to int
/// @param nptr
/// @return final int
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		if (nptr[i] == '+')
			sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/* int main(void)
{
	char    a [] = "-1";
	char    b [] = "1";
	char    c [] = " 1";
	char    d [] = " +1";
	char    e [] = " a1";


	printf("%s\n", a);
	ft_atoi(a);
	printf("%s\n", a);


	printf("%s\n", b);
	ft_atoi(b);
	printf("%s\n", b);


	printf("%s\n", c);
	ft_atoi(c);
	printf("%s\n", c);


	printf("%s\n", d);
	ft_atoi(d);
	printf("%s\n", d);


	printf("%s\n", e);
	ft_atoi(e);
	printf("%s\n", e);
	return (0);
