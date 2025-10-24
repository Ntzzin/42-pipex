/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:45:54 by nado-nas          #+#    #+#             */
/*   Updated: 2025/09/04 11:38:39 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_words(char const *s, char c)
{
	int	ct;
	int	i;

	i = 0;
	ct = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			ct++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (ct);
}

/**
 * @brief Allocates (with malloc(3)) and copies the next word
 * from the string 's', stopping at the delimiter 'c'.
 * @param dst A pointer to the variable where the allocated word
 * will be stored.
 * @param s The string to analyze, starting from the current position.
 * @param c The delimiter character.
 * @return The length of the copied word (excluding '\0').
 * If allocation fails it returns the lenght that the word
 * would have and '*dst' will be NULL.
 */
static int	ft_word(char **dst, char const *s, char c)
{
	int	wlen;

	wlen = ft_wordlen(s, c) + 1;
	*dst = malloc(wlen);
	if (*dst)
		ft_strlcpy(*dst, s, wlen);
	return (wlen - 1);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**l;
	int		i;
	int		j;

	l = malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!l)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			i += ft_word(&(l[j]), &(s[i]), c);
			j++;
		}
	}
	l[j] = NULL;
	return (l);
}
