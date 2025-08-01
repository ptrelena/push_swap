/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 13:20:26 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 13:20:26 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy 'size' 1st bytes from src in dst
/// @param dst
/// @param src
/// @param size
/// @return dstlen + srclen
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size == 0)
		return (srclen);
	if (size <= dstlen)
		return (size + srclen);
	while (src[i] != '\0' && dstlen + i < size - 1)
	{
		dst[(dstlen + i)] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

/* int main(void)
{
	char    a [] = "Manolo";
	char    b [] = "Aurelio";
	size_t  c = 3;

	printf("%s\n", a);
	printf("%s\n", b);
	printf("%zu\n", ft_strlcat(a, b, c));
	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
} */
