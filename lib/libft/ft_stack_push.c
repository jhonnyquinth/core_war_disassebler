/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:38:16 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 22:48:14 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_stack **begin_list, void *data)
{
	t_stack *list;

	list = ft_stack_make(data);
	list->next = *begin_list;
	*begin_list = list;
}
