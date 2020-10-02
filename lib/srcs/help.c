/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 00:16:07 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/07 05:40:07 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		min_int(int a, int b)
{
	return (a > b ? b : a);
}

int		max_int(int a, int b)
{
	return (a > b ? a : b);
}

char	*ft_itoa_base(int value, int base)
{
	long				n;
	int					i;
	int					sgn;
	char				*s;

	n = (value < 0) ? -(long)value : value;
	sgn = (value < 0 && base == 10) ? -1 : 0;
	i = (sgn == -1) ? 2 : 1;
	while (n / base > 0)
	{
		i++;
		n /= base;
	}
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sgn)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char	*ft_itoa_base_us(long long value, int base)
{
	intmax_t			n;
	int					i;
	char				*s;

	if (value == (-9223372036854775807 - 1))
		return (ft_strdup("9223372036854775808"));
	n = (value < 0) ? ((-1) * value) : value;
	i = 1;
	while (n / base > 0)
	{
		i++;
		n /= base;
	}
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}

char	*ft_itoa_base_ox(unsigned long long value, int base, char c)
{
	unsigned long long	n;
	int					i;
	char				*s;
	char				x;

	x = (c == 'x') ? 'a' : 'A';
	n = value;
	i = 1;
	while (n / base > 0)
	{
		i++;
		n /= base;
	}
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + x - 10;
		n /= base;
	}
	return (s);
}
