/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 13:19:31 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 13:19:31 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy from src to dst 'len' bytes
/// @param dst
/// @param src
/// @param len
/// @return dst
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || dst == src)
		return (dst);
	if ((const unsigned char *)src > (const unsigned char *)dst)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char	a [] = "Elena Juana";
	char	b [] = "Maria";
	size_t	c = 5;

	printf("%s\n", a);
	printf("%s\n", b);
	ft_memmove(a, b, c);
	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
} */
