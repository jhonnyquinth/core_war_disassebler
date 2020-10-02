/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 07:34:49 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 07:35:48 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_sub(char *str)
{
	int			cnt;

	cnt = 0;
	while ((*str != '%') && (*str) && (*str != 'c') && (*str != 's') && \
	(*str != 'p') && (*str != 'd') && (*str != 'i') && (*str != 'o') && \
	(*str != 'u') && (*str != 'x') && (*str != 'X') && (*str != 'f'))
	{
		cnt++;
		str++;
	}
	return (cnt + 1);
}

int			rcl_percent_killer(t_persent **lst, char **cm_str, int *sf, int len)
{
	char	*sub;

	len = get_sub(*cm_str + 1);
	sub = ft_strsub(*cm_str + 1, 0, len);
	if (!(*sf))
		*lst = list_make();
	if (sub_proc(sub, *lst, *sf))
	{
		free(sub);
		return (1);
	}
	get_tail(*cm_str + len, *lst);
	*cm_str += len + 1;
	free(sub);
	(*sf)++;
	return (0);
}

void		rcl_iter(int *l, char **cm_str, int sf)
{
	if (!sf)
	{
		ft_putchar(**cm_str);
		(*l)++;
	}
	(*cm_str)++;
}

t_persent	*read_command_line(char *cm_str, int *l, int *cnt)
{
	t_persent	*lst;
	int			len;
	int			start_flag;

	lst = NULL;
	len = 0;
	start_flag = 0;
	while (*cm_str)
	{
		if (*cm_str == '%')
		{
			if (rcl_percent_killer(&lst, &cm_str, &start_flag, len))
			{
				list_all_free(lst);
				return (NULL);
			}
			(*cnt)++;
		}
		else
			rcl_iter(l, &cm_str, start_flag);
	}
	return (lst);
}
