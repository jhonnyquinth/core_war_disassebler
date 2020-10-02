/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ox_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 06:49:53 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 06:50:38 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ox_o_presison(t_persent *lst, char *s, int len, int c)
{
	while (lst->precision > len)
	{
		len++;
		ft_putchar('0');
	}
	print_heshes(c, lst);
	len += c;
	ft_putstr(s);
	(*s) ? free(s) : 0;
	return (len);
}

int		ox_o_width(t_persent *lst, char *s, int len, int c)
{
	int	p;

	p = c + max_int(len, lst->precision);
	while (!(lst->f_mns) && (lst->width > p++))
		ft_putchar((lst->f_zro) ? '0' : ' ');
	if (c)
		ft_putchar('0');
	while (lst->precision > len)
	{
		len++;
		ft_putchar('0');
	}
	ft_putstr(s);
	while (lst->f_mns && (lst->width > p++))
		ft_putchar((lst->f_zro) ? '0' : ' ');
	(*s) ? free(s) : 0;
	return (max_int(lst->width, c + len));
}
