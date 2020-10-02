/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mantis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:12:42 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:38 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*parse_mantis(unsigned long mantissa)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * 65);
	ft_bzero(str, 65);
	str[64] = '\0';
	i = 0;
	while (i < 64)
	{
		str[i] = '0';
		i++;
	}
	str = make_mantissa(str, mantissa);
	return (str);
}

void	fill_exp_mant(t_mult *m, char **a, char **b)
{
	m->str2 = *a;
	m->str1 = *b;
	m->len1 = ft_strlen(*a) - 1;
	m->len2 = ft_strlen(*b) - 1;
}
