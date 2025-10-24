/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:19:21 by nado-nas          #+#    #+#             */
/*   Updated: 2025/08/29 18:38:47 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	void			*res;
	size_t			i;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	res = NULL;
	i = 0;
	while (i < n && ps[i] != (unsigned char)c)
	{
		pd[i] = ps[i];
		i++;
	}
	if (ps[i] == (unsigned char)c && i < n)
	{
		pd[i] = ps[i];
		res = (void *)&(pd[++i]);
	}
	return (res);
}
