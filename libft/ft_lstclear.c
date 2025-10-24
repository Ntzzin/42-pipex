/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:54:08 by nado-nas          #+#    #+#             */
/*   Updated: 2025/09/06 17:09:26 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Deletes and frees the given element and every successor 
 * of that element, using the function ’del’ and free(3). Finally, 
 * the pointer to the list must be set to NULL.
 * @param lst The adress of a pointer to an element.
 * @param del The adress of the function used to delete the
 * content of the element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*next;

	if (lst && del)
	{
		curr = *lst;
		while (curr)
		{
			next = curr->next;
			ft_lstdelone(curr, del);
			curr = next;
		}
		*lst = NULL;
	}
}
