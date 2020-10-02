/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:17:18 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/12 17:17:20 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *root;
	t_list *next;

	root = *alst;
	while (root && *alst)
	{
		next = root->next;
		(*del)(root->content, root->content_size);
		free(root);
		root = next;
	}
	*alst = NULL;
	next = NULL;
}
