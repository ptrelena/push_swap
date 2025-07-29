/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenpere <elenpere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 13:16:33 by elenpere          #+#    #+#             */
/*   Updated: 2025-01-16 13:16:33 by elenpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief set bytes as 0 (nothing to return)
/// @param s - initial ptr
/// @param n - num of bytes to set
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return ;
}

/* int	main(void)
{
	char	str [] = "Elena";
	size_t	n = 5;
	printf("%s\n", str);
	ft_bzero(str, n);
	printf("%s\n", str);
	return (0);
}

