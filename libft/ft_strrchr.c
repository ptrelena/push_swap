/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 15:57:19 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 15:57:19 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates last occurrence of c in s
/// @param s
/// @param c
/// @return ptr to location of c
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
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

	printf("a: %c\n", *ft_strrchr(a1, a2));
	printf("b: %c\n", *ft_strrchr(b1, b2));
	printf("d: %c\n", *ft_strrchr(d1, d2));
	printf("e: %c\n", *ft_strrchr(e1, e2));
	printf("f: %c\n", *ft_strrchr(f1, f2));
	printf("c: %c\n", *ft_strrchr(c1, c2));
	return (0);
} */
