/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:00:23 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 07:09:28 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_persent	*list_make(void)
{
	t_persent *tmp;

	tmp = NULL;
	if ((tmp = malloc(sizeof(t_persent))))
	{
		tmp->flag_checker = 0;
		tmp->modf = 0;
		tmp->f_hesh = 0;
		tmp->f_mns = 0;
		tmp->f_pls = 0;
		tmp->f_sps = 0;
		tmp->f_zro = 0;
		tmp->sign = 0;
		tmp->width = -1;
		tmp->precision = -1;
		tmp->trans = 0;
		tmp->tail = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

t_persent	*list_add(t_persent *head)
{
	t_persent *curr;
	t_persent *new;

	curr = head;
	while (curr->next)
	{
		curr = curr->next;
	}
	new = list_make();
	curr->next = new;
	return (curr->next);
}

void		list_pop(t_persent *head)
{
	t_persent *prew;

	prew = NULL;
	while (head->next)
	{
		prew = head;
		head = head->next;
	}
	free(head);
	prew->next = NULL;
}

t_persent	*list_free(t_persent *head)
{
	t_persent *tmp;

	tmp = NULL;
	if (head)
	{
		if (head->tail)
			free(head->tail);
		if (head->next)
		{
			tmp = head->next;
		}
		free(head);
	}
	return (tmp);
}

void		list_all_free(t_persent *head)
{
	while (head)
	{
		head = list_free(head);
	}
}
