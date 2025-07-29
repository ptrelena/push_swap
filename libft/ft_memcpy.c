/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 13:18:36 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 13:18:36 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy data from src to dest
/// @param dest
/// @param src declared as 'const void*', data won't be modified in src
/// @param n number of bytes to be copied
/// @return void
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s || n <= 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/* int	main(void)
{
	char	a [] = "Elena";
	char	b [] = "Juana";
	size_t	c = 2;

	printf("%s\n", a);
	printf("%s\n", b);
	ft_memcpy(a, b, c);
	printf("%s\n", a);
	printf("%s\n", b);
	return(0);
} */
