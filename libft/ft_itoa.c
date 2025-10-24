/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:40:25 by nado-nas          #+#    #+#             */
/*   Updated: 2025/09/04 14:52:38 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_nsize(long n)
{
	int	sig;

	sig = 0;
	if (n < 0)
	{
		n *= -1;
		sig = 1;
	}
	if (n < 10)
		return (1 + sig);
	return (1 + sig + ft_nsize(n / 10));
}

static char	*ft_strnbr(char *dst, long n, int i)
{
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
	}
	dst[i] = (n % 10) + '0';
	if (n >= 10)
		return (ft_strnbr(dst, n / 10, i - 1));
	return (dst);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the
 * allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	i = ft_nsize(n);
	nbr = malloc(i + 1);
	if (!nbr)
		return (NULL);
	nbr[i--] = '\0';
	return (ft_strnbr(nbr, (long)n, i));
}
