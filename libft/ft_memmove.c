/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:42:27 by nado-nas          #+#    #+#             */
/*   Updated: 2025/08/30 15:30:05 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n--)
			pd[n] = ps[n];
	}
	return ((void *)pd);
}
