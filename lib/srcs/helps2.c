/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 07:02:36 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 07:07:26 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pres_c(t_persent *lst, int len, char c)
{
	int		ch;

	if (c != '\0')
		ft_putchar(c);
	ch = (c == '\0') ? 1 : 0;
	while (lst->precision >= (len + ch))
	{
		lst->precision -= 1;
		ft_putchar('0');
	}
}

int		check_width(char *str, t_persent *lst)
{
	int			width;

	width = ft_atoi(str);
	if (width != 0)
	{
		lst->width = width;
		return (ft_len(width));
	}
	return (0);
}

int		check_precision(char *str, t_persent *lst)
{
	int			precision;
	int			zero_cnt;

	precision = 0;
	zero_cnt = 0;
	if (*str != '.')
		return (0);
	str++;
	precision = ft_atoi(str);
	lst->precision = precision;
	while (*str == '0')
	{
		zero_cnt++;
		str++;
	}
	if (precision != 0)
		return (ft_len(precision) + zero_cnt + 1);
	return (zero_cnt + 1);
}
