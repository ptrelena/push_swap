/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:02:23 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 16:02:23 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief compare s1 & s2 in 'n' bytes
/// @param s1
/// @param s2
/// @param n
/// @return if equal 0, if different s1[i] - s2[i]
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{

	char   a1 [] = "ElenaElenita";
	char    a2 [] = "ElenaElenita";

	char    b1 [] = "ElenaElenita";
	char    b2 [] = "CarlosCarlitos";

	char    c1 [] = "ElenaElenita";
	char    c2 [] = "Elenita'\0'Carlos";
	size_t  z = 10;

	printf("a: %d\n", ft_memcmp(a1, a2, z));
	printf("b: %d\n", ft_memcmp(b1, b2, z));
	printf("c: %d\n", ft_memcmp(c1, c2, z));
	return (0);
