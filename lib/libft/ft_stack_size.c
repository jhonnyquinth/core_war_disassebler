/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:41:47 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 22:53:32 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_stack_size(t_stack *begin_list)
{
	size_t n;

	n = 0;
	while (begin_list)
	{
		n++;
		begin_list = begin_list->next;
	}
	return (n);
}
