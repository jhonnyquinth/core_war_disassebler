/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:13:28 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:24 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*nan_inf_str(char tmp, int type)
{
	char		*str;
	int			i;

	if (!(str = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	i = -1;
	if (tmp == 'i')
		while (++i < 3)
		{
			if (type == 5)
				str[i] = INF_UP[i];
			else
				str[i] = INF[i];
		}
	else
		while (++i < 3)
		{
			if (type == 5)
				str[i] = NAN_UP[i];
			else
				str[i] = NAN[i];
		}
	str[i] = '\0';
	return (str);
}

char	*is_nan(unsigned long mantissa, int type)
{
	uint64_t	head;
	uint64_t	tail;

	head = mantissa >> 62;
	tail = mantissa << 2;
	if (head == 1 || head == 3)
		return (nan_inf_str('n', type));
	else
	{
		if (tail == 0)
			return (nan_inf_str('i', type));
		else
			return (nan_inf_str('n', type));
	}
}

void	pars_nan_inf(t_persent *data, char str)
{
	if (str == 'i' || str == 'I' || str == 'n' || str == 'N')
	{
		if (str == 'n' || str == 'N')
		{
			data->f_sps = 0;
			data->f_pls = 0;
		}
		data->f_zro = 0;
	}
}
