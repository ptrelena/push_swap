/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 15:59:41 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 15:59:41 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates first occurrence of 'c' in in 'n' bytes from s
/// @param s
/// @param c
/// @param n
/// @return NULL
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (t[i] == (unsigned char)c)
			return (&t[i]);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
	size_t t = 4;

	char    a1 [] = "Piscine";
	int     a2 = 's';

	char    b1 [] = "Piscine";
	int     b2 = 'P';

	char    c1 [] = "Piscine";
	int     c2 = 'z';

	char    d1 [] = "Piscine";
	int     d2 = '\0';

	char    e1 [] = "Piscine";
	int     e2 = 'i';

	printf("a: %p\n", a1);
	printf("a: %p\n",ft_memchr(a1, a2, t));
	printf("b: %p\n", b1);
	printf("b: %p\n",ft_memchr(b1, b2, t));
	printf("c: %p\n", c1);
	printf("c: %p\n",ft_memchr(c1, c2, t));
	printf("d: %p\n", d1);
	printf("d: %p\n",ft_memchr(d1, d2, t));
	printf("e: %p\n", e1);
	printf("e: %p\n",ft_memchr(e1, e2, t));
	return (0);
