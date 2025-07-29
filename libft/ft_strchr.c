/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 15:56:04 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 15:56:04 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief finds ptr of first occurrence of 'c' in 's'
/// @param s
/// @param c
/// @return ptr c position in s
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

/* int main()
{

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

	char    f1 [] = "Piscine end";
	int     f2 = 'e';

	printf("a: %s\n", ft_strchr(a1, a2));
	printf("b: %s\n", ft_strchr(b1, b2));
	printf("c: %s\n", ft_strchr(c1, c2));
	printf("d: %s\n", ft_strchr(d1, d2));
	printf("e: %s\n", ft_strchr(e1, e2));
	printf("f: %s\n", ft_strchr(f1, f2));
	return (0);
} */
