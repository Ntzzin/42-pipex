/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:56:55 by nado-nas          #+#    #+#             */
/*   Updated: 2025/09/01 15:23:08 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the 
 * string ’s’. The substring begins at index ’start’ and is of maximum 
 * size ’len’.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	srclen;
	size_t	sublen;

	sublen = 0;
	srclen = ft_strlen((char *)s);
	if (start < srclen)
	{
		if (srclen - start < len)
			sublen = srclen - start;
		else
			sublen = len;
	}
	sub = malloc(sublen + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &(s[start]), sublen);
	sub[sublen] = '\0';
	return (sub);
}
