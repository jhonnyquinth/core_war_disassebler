/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:36:44 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 22:56:35 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_make(void *data)
{
	t_stack *tmp;

	tmp = NULL;
	if ((tmp = malloc(sizeof(t_stack))))
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}
