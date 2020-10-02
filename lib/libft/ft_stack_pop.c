/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:41:52 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 22:48:44 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stack_pop(t_stack **list)
{
	void	*item;
	t_stack	*next;

	item = (*list)->data;
	next = (*list)->next;
	free(*list);
	*list = next;
	return (item);
}
