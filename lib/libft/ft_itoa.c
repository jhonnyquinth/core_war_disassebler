/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:50:20 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 20:40:40 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return ((-1) * n);
}

static int	ft_len(int n)
{
	int l;

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

static void	ft_nbr(int l, int i, int n, char **str)
{
	int ten;

	l = l - i;
	ten = 1;
	while (l != 1)
	{
		ten *= 10;
		l--;
	}
	while (ten != 0)
	{
		(*str)[i++] = ft_abs(n / ten) + '0';
		n %= ten;
		ten /= 10;
	}
	(*str)[i] = '\0';
}

char		*ft_itoa(int n)
{
	int		l;
	char	*str;
	int		i;

	l = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	ft_nbr(l, i, n, &str);
	return (str);
}
