/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:22:19 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 07:03:39 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	pf_make_c(t_persent *lst, int *len, int sgn)
{
	if (sgn)
	{
		if (lst->f_pls == 1)
		{
			(*len)++;
			return ('+');
		}
		else if (lst->f_sps == 1)
		{
			(*len)++;
			return (' ');
		}
		return ('\0');
	}
	(*len)++;
	return ('-');
}

int		pf_precision(t_persent *lst, char *s, int len, char c)
{
	int	p;

	p = (lst->precision == -1) ? 0 : lst->precision;
	if ((lst->precision == 0) && (*s == '0'))
	{
		if (lst->f_pls == 1)
		{
			ft_putchar('+');
			return (1);
		}
		(*s && s) ? free(s) : 0;
		return (0);
	}
	pres_c(lst, len, c);
	ft_putstr(s);
	(*s && s) ? free(s) : 0;
	return (max_int(len, p + (c != '\0')));
}

int		pf_width(t_persent *lst, int len, char *s, char c)
{
	int p;

	p = (lst->precision == -1) ? 0 : lst->precision;
	p = (lst->precision == 0) && (*s == '0') ?\
	lst->width : lst->width - max_int(len, p + (c != '\0'));
	if (lst->precision == 0)
		p -= lst->f_pls;
	if ((lst->f_mns || (lst->f_zro && (lst->precision == -1))) && (c != '\0'))
		ft_putchar(c);
	while (!(lst->f_mns) && p--)
		ft_putchar((lst->f_zro && (lst->precision == -1)) ? '0' : ' ');
	if (!(lst->f_mns) && !(lst->f_zro && (lst->precision == -1)) && (c != '\0'))
		ft_putchar(c);
	while (lst->precision >= (len + (c == '\0')))
	{
		lst->precision -= 1;
		ft_putchar('0');
	}
	if (!((lst->precision == 0) && (*s == '0')))
		ft_putstr(s);
	while (lst->f_mns && p--)
		ft_putchar(' ');
	(*s && s) ? free(s) : 0;
	return (lst->width);
}

int		n_int(long long n, t_persent *lst)
{
	int		p;
	int		len;
	char	c;
	char	*s;

	s = ft_itoa_base_us(n, 10);
	len = ft_strlen(s);
	c = pf_make_c(lst, &len, (n >= 0) ? 1 : 0);
	p = (lst->precision == -1) ? 0 : lst->precision;
	if (max_int(len, p) >= lst->width)
		return (pf_precision(lst, s, len, c));
	return (pf_width(lst, len, s, c));
}

int		type_int(va_list arg, t_persent *lst)
{
	int		len;

	len = 0;
	if (lst->modf == 0)
		len = n_int(va_arg(arg, int), lst);
	if (lst->modf == 1)
		len = n_int((short int)va_arg(arg, int), lst);
	if (lst->modf == 2)
		len = n_int((char)va_arg(arg, int), lst);
	if (lst->modf == 3)
		len = n_int(va_arg(arg, long int), lst);
	if (lst->modf == 4)
		len = n_int(va_arg(arg, long long), lst);
	return (len);
}
