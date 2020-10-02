/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:46:55 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 06:50:37 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*to_str(t_persent *lst, long long n)
{
	if (lst->trans == 'o')
		return (ft_itoa_base_ox(n, 8, lst->trans));
	if (lst->trans == 'u')
		return (ft_itoa_base_ox(n, 10, lst->trans));
	else
		return (ft_itoa_base_ox(n, 16, lst->trans));
}

int		heshs(t_persent *lst, char c)
{
	if (lst->f_hesh)
	{
		if ((lst->trans == 'x') && (c != '0'))
			return (2);
		else if ((c != '0') && (lst->trans == 'X'))
			return (2);
		else if (lst->trans == 'o')
			return (1);
	}
	return (0);
}

int		print_heshes(int c, t_persent *lst)
{
	if ((c != 1) && (c != 2))
		return (0);
	ft_putchar('0');
	if (c == 2)
		ft_putchar(lst->trans);
	return (0);
}

void	pres_h(t_persent *lst, int len, int c)
{
	print_heshes(c, lst);
	while (lst->precision > (len - ((c == 2) ? 2 : 0)))
	{
		lst->precision -= 1;
		ft_putchar('0');
	}
}

int		value_for_pres(t_persent *lst, int len, int c)
{
	if (lst->trans == 'o')
		return (lst->precision >= (len + !(c)));
	else
		return (lst->precision > (len - c));
}
