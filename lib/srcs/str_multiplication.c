/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_multiplication.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:25:01 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:49 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*str_multiplication(t_mult *m, char *tmp)
{
	int i;
	int j;
	int shift;
	int mem;
	int res;

	shift = 0;
	i = m->len2 + 1;
	while (--i >= 0)
	{
		j = m->len1 + 1;
		mem = 0;
		while (--j >= 0)
		{
			res = (m->str1[i] - '0') * (m->str2[j] - '0') +
			(tmp[j + m->len2 + 1 - shift] - '0') + mem;
			mem = res / 10;
			tmp[j + m->len2 + 1 - shift] = res % 10 + '0';
			if (j == 0)
				tmp[i] = mem + '0';
		}
		shift++;
	}
	tmp[m->len2 + m->len1 - 1] = '\0';
	return (tmp);
}

char	*pow_two(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int i;

	len = pow * 0.301 + 1;
	ret = 0;
	res[len] = '\0';
	res[len - 1] = '2';
	i = -1;
	while (i++ < (len - 2))
		res[i] = '0';
	while (pow > 1)
	{
		len = ft_strlen(res) - 1;
		while (len >= 0)
		{
			dec = res[len] - '0';
			res[len--] = (dec * 2 + ret) % 10 + '0';
			ret = (dec * 2 + ret) < 10 ? 0 : 1;
		}
		res[len] = ret + '0';
		pow--;
	}
	return (res);
}

char	*pow_five(char *res, int pow)
{
	int len;
	int ret;
	int dec;
	int i;

	len = pow;
	ret = 0;
	res[pow] = '\0';
	res[len - 1] = '5';
	i = -1;
	while (i++ < (len - 2))
		res[i] = '0';
	while (pow > 1)
	{
		len = ft_strlen(res) - 1;
		while (len > 0)
		{
			dec = res[len] - '0';
			res[len--] = (dec * 5 + ret) % 10 + '0';
			ret = (dec * 5 + ret) < 10 ? 0 : ((dec * 5 + ret) / 10);
		}
		res[len] = ret + '0';
		pow--;
	}
	return (res);
}
