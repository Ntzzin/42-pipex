/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:20:39 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/21 10:46:00 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ to the content of each element. Creates a new list 
 * resulting of the successive applications of the function 
 * ’f’. The ’del’ function is used to delete the content of 
 * an element if needed.
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on
 * the list.
 * @param del The address of the function used to delete 
 * the content.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	l = NULL;
	node = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		ft_lstadd_back(&l, node);
		lst = lst->next;
	}
	return (l);
}
