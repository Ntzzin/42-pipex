/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:05 by nado-nas          #+#    #+#             */
/*   Updated: 2025/09/01 15:49:20 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jn;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	jn = malloc(len);
	if (!jn)
		return (NULL);
	jn[0] = '\0';
	ft_strlcat(jn, s1, len);
	ft_strlcat(jn, s2, len);
	return (jn);
}
