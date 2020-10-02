/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_poc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:18:36 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 07:25:02 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_flag(char *str, t_persent *lst, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		if (str[i] == ' ')
			lst->f_sps = 1;
		if (str[i] == '#')
			lst->f_hesh = 1;
		if (str[i] == '-')
			lst->f_mns = 1;
		if (str[i] == '+')
			lst->f_pls = 1;
		if (str[i] == '0')
			lst->f_zro = 1;
		if ((str[i] != ' ') && (str[i] != '#') && (str[i] != '-') &&
			(str[i] != '+') && (str[i] != '0'))
			return (i);
		else
		{
			lst->flag_checker = 1;
			i++;
		}
	}
	return (i);
}

int		ft_len(int n)
{
	int			l;

	if (n >= 0)
		l = 1;
	else
		l = 2;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

int		check_modificator(char *str, t_persent *lst)
{
	if (*str == 'L')
		return (1 + (lst->modf = 5) * 0);
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
		{
			lst->modf = 4;
			return (2);
		}
		lst->modf = 3;
		return (1);
	}
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
		{
			lst->modf = 2;
			return (2);
		}
		lst->modf = 1;
		return (1);
	}
	return (0);
}

int		check_transformator(char *str, t_persent *lst)
{
	while (*str == ' ')
		str++;
	if ((*str == '%') || (*str == 'c') || (*str == 's') || \
	(*str == 'p') || (*str == 'd') || (*str == 'i') || (*str == 'o') \
	|| (*str == 'u') || (*str == 'x') || (*str == 'X') || (*str == 'f'))
		lst->trans = *str;
	else
		return (1);
	return (0);
}

int		sub_proc(char *str, t_persent *lst, int start_flag)
{
	int			len;
	t_persent	*new;

	if (start_flag)
		new = list_add(lst);
	else
		new = lst;
	len = ft_strlen(str);
	str += check_flag(str, new, min_int(5, len));
	str += check_width(str, new);
	str += check_precision(str, new);
	str += check_modificator(str, new);
	return (check_transformator(str, new));
}
