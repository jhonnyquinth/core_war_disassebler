/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prinf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:51:12 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 08:13:41 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_tail(char *str, t_persent *lst)
{
	t_persent	*last;
	int			n;

	if (*str != '\0')
		str++;
	last = lst;
	n = 0;
	while (last->next)
		last = last->next;
	while ((str[n] != '%') && (str[n] != '\0'))
		n++;
	last->tail = ft_strsub(str, 0, n);
	return (0);
}

char		*proc_str_generator(int n)
{
	char		*s;
	int			i;

	if ((s = ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	s[n] = '\0';
	while (n > i)
		s[i++] = '%';
	return (s);
}

int			choose_trans(t_persent *curr, va_list arg, int len)
{
	if (curr->trans == 'c')
		len += type_char((char)va_arg(arg, int), curr);
	if (curr->trans == 's')
		len += type_str(va_arg(arg, char*), curr);
	if ((curr->trans == 'd') || (curr->trans == 'i'))
		len += type_int(arg, curr);
	if (curr->trans == 'f')
		len += type_float(curr, arg);
	if (curr->trans == '%')
		len += type_proc(curr);
	if ((curr->trans == 'u') || (curr->trans == 'x') ||
		(curr->trans == 'X') || (curr->trans == 'o'))
		len += type_ox(arg, curr);
	if (curr->trans == 'p')
		len += type_ptr(va_arg(arg, unsigned long long), curr);
	if ((curr->trans != 0))
	{
		ft_putstr(curr->tail);
		len += ft_strlen(curr->tail);
	}
	return (len);
}

int			ft_printf(char *cm_str, ...)
{
	int			arg_cntr;
	int			len;
	t_persent	*lst;
	t_persent	*curr;
	va_list		arg;

	len = 0;
	arg_cntr = 0;
	lst = read_command_line(cm_str, &len, &arg_cntr);
	curr = lst;
	va_start(arg, cm_str);
	while (arg_cntr-- > 0)
	{
		len = choose_trans(curr, arg, len);
		curr = list_free(curr);
	}
	va_end(arg);
	return (len);
}

int			type_float(t_persent *data, va_list ap)
{
	long double	f;
	int			i;

	i = 0;
	f = 0.0;
	if (data->modf == 5)
		f = va_arg(ap, long double);
	else
		f = (long double)va_arg(ap, double);
	i = parse_float(data, f);
	return (i);
}
