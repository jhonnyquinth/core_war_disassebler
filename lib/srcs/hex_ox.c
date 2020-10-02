/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 06:47:49 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 06:49:20 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ox_o(long long n, t_persent *lst)
{
	int		len;
	int		c;
	char	*s;

	s = to_str(lst, n);
	if (*s == '0' && lst->precision == 0)
	{
		free(s);
		s = "";
		len = 0;
	}
	else
		len = ft_strlen(s);
	lst->f_zro = (lst->f_mns || (lst->precision != -1)) ? 0 : lst->f_zro;
	lst->f_zro = ((*s == '0') && (lst->precision != -1)) ? 0 : lst->f_zro;
	lst->precision = (lst->precision <= len) ? -1 : lst->precision;
	lst->f_hesh = (*s == '0' && (lst->precision != 0))\
	|| lst->precision > 0 ? 0 : lst->f_hesh;
	c = heshs(lst, *s);
	if (max_int(len, lst->precision) >= lst->width)
		return (ox_o_presison(lst, s, len, c));
	return (ox_o_width(lst, s, len, c));
}

int		ox_presison(t_persent *lst, char *s, int len, int c)
{
	int	p;

	p = (lst->precision == -1) ? 0 : lst->precision;
	if ((lst->precision == 0) && (*s == '0'))
	{
		free(s);
		if ((lst->trans == 'o') && lst->f_hesh)
		{
			ft_putchar('0');
			return (1);
		}
		else
			return (0);
	}
	if ((*s != '0') || (lst->trans != 'o') || !(lst->f_hesh))
	{
		pres_h(lst, len, c);
	}
	else
		len--;
	ft_putstr(s);
	free(s);
	return (max_int(len, p + ((c == 2) ? 2 : 0)));
}

int		ox_width(t_persent *lst, char *s, int len, int c)
{
	int	p;

	p = (lst->precision == -1) ? 0 : lst->precision;
	p = (lst->precision == 0) && (*s == '0') ? lst->width -\
	(lst->f_hesh && lst->trans == 'o') : lst->width - max_int(len, p + c);
	if ((lst->f_mns || (lst->f_zro && (lst->precision == -1))) && (c != '\0'))
		print_heshes(c, lst);
	while (!(lst->f_mns) && p--)
		ft_putchar((lst->f_zro && (lst->precision == -1)) ? '0' : ' ');
	if (!(lst->f_mns) && !(lst->f_zro && (lst->precision == -1)) && (c != '\0'))
		print_heshes(c, lst);
	while (value_for_pres(lst, len, c))
	{
		lst->precision -= 1;
		ft_putchar('0');
	}
	if (!((lst->precision == 0) && (*s == '0')))
		ft_putstr(s);
	while (lst->f_mns && p--)
		ft_putchar(' ');
	free(s);
	return (lst->width);
}

int		ox(long long n, t_persent *lst)
{
	int		p;
	int		len;
	int		c;
	char	*s;

	if (lst->trans == 'o')
		return (ox_o(n, lst));
	s = to_str(lst, n);
	len = ft_strlen(s);
	c = heshs(lst, *s);
	len += c;
	p = (lst->precision == -1) ? 0 : lst->precision;
	if (max_int(len, p) >= lst->width)
		return (ox_presison(lst, s, len, c));
	return (ox_width(lst, s, len, c));
}

int		type_ox(va_list arg, t_persent *lst)
{
	int		len;

	len = 0;
	if (lst->modf == 0)
		len = ox(va_arg(arg, unsigned int), lst);
	if (lst->modf == 1)
		len = ox((unsigned short int)va_arg(arg, int), lst);
	if (lst->modf == 2)
		len = ox((unsigned char)va_arg(arg, int), lst);
	if (lst->modf == 3)
		len = ox((unsigned long int)va_arg(arg, unsigned long int), lst);
	if (lst->modf == 4)
		len = ox((unsigned long long int)va_arg(arg, unsigned long long int),
			lst);
	return (len);
}
