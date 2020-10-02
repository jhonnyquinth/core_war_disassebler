/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:24:25 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 06:09:49 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		type_char(char c, t_persent *lst)
{
	int		i;

	i = 1;
	if (lst->width == -1)
	{
		ft_putchar(c);
		return (1);
	}
	if (lst->f_mns == 1)
		ft_putchar(c);
	while (++i <= lst->width)
		ft_putchar((lst->f_zro && !lst->f_mns) ? '0' : ' ');
	if (lst->f_mns != 1)
		ft_putchar(c);
	return (lst->width);
}

int		type_str(char *str, t_persent *lst)
{
	int		len;
	char	*sub;
	int		nulls;

	if (!str)
	{
		str = "(null)";
	}
	len = ft_strlen(str);
	if (lst->precision != -1)
		len = min_int(len, lst->precision);
	sub = ft_strsub(str, 0, len);
	if (lst->f_mns == 1)
		ft_putstr(sub);
	nulls = 0;
	if (lst->width != -1)
	{
		nulls = (lst->width > len) ? (lst->width - len) : 0;
	}
	while (nulls-- > 0)
		ft_putchar((lst->f_zro && !lst->f_mns) ? '0' : ' ');
	if (lst->f_mns != 1)
		ft_putstr(sub);
	free(sub);
	return ((lst->width > len) ? lst->width : len);
}

int		type_proc(t_persent *lst)
{
	int		i;

	i = 1;
	if (lst->width == -1)
	{
		ft_putchar('%');
		return (1);
	}
	if (lst->f_mns)
		ft_putchar('%');
	while (i++ < lst->width)
		ft_putchar((lst->f_zro && !(lst->f_mns)) ? '0' : ' ');
	if (!lst->f_mns)
		ft_putchar('%');
	return (lst->width);
}

int		ft_putptr(char *s, t_persent *lst, int *len)
{
	ft_putstr("0x");
	while (lst->precision > (*len - 2))
	{
		(*len)++;
		ft_putchar('0');
	}
	if (lst->precision != 0 || *s != '0')
		ft_putstr(s);
	free(s);
	return (2);
}

int		type_ptr(unsigned long long p, t_persent *lst)
{
	char	*str;
	int		len;

	str = ft_itoa_base_ox(p, 16, 'x');
	if (lst->precision == 0 && *str == '0')
		len = 2;
	else
		len = ft_strlen(str) + 2;
	if (lst->f_mns)
		ft_putptr(str, lst, &len);
	while (lst->width > max_int(len, lst->precision))
	{
		len++;
		ft_putchar(' ');
	}
	if (lst->f_mns != 1)
		ft_putptr(str, lst, &len);
	return (len);
}
