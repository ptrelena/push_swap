/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:03:05 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 16:03:05 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief finds little in big
/// @param big
/// @param little
/// @param len
/// @return
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[j + i] == little[j]) && ((i + j) < len))
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{

	char	a1 [] = "Street";
	char	a2 [] = "Str";

	char	b1 [] = "Street";
	char	b2 [] = "tree";

	char	c1 [] = "Street";
	char	c2 [] = "str";
	size_t	t = 3;

	printf("%s\n", ft_strnstr(a1, a2, t));
	printf("%s\n", ft_strnstr(b1, b2, t));
	printf("%s\n", ft_strnstr(c1, c2, t));
	return (0);
} */
