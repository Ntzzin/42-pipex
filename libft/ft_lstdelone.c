/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:45:07 by nado-nas          #+#    #+#             */
/*   Updated: 2025/09/06 17:06:10 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Takes as a parameter an element and frees the
 * memory of the element’s content using the function
 * ’del’ given as a parameter and free the element.
 * The memory of ’next’ must not be freed.
 * @param lst The element to free.
 * @param del The address of the function used to delete 
 * the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
