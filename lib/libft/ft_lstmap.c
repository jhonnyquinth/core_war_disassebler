/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:19 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/12 17:18:23 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;
	t_list *start;
	t_list *fin;

	if (!lst)
		return (NULL);
	start = (*f)(lst);
	l = ft_lstnew(start->content, start->content_size);
	fin = l;
	while (lst->next)
	{
		lst = lst->next;
		start = (*f)(lst);
		l->next = ft_lstnew(start->content, start->content_size);
		if (l->next == NULL)
		{
			free(l->next);
			l->next = l;
		}
		l = l->next;
	}
	return (fin);
}
