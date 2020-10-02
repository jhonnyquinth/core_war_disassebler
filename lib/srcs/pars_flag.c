/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:22:22 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:34 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		parse_float_flag2(t_persent *data, int num_len)
{
	if (data->width)
		(data->width >= num_len) ? (data->width -= num_len) : (data->width = 0);
	if (data->f_sps)
		if (data->f_pls || data->sign)
			data->f_sps = 0;
	if (data->f_pls)
		if (data->sign == 1)
			data->f_pls = 0;
	if (data->f_zro)
		if (data->f_mns)
			data->f_zro = 0;
	return (data->width - data->f_pls - data->sign - data->f_sps);
}

char	*parse_float_flag(t_persent *data, int num_len)
{
	int		i;
	int		str_len;
	char	*str_flag;

	i = 0;
	str_flag = NULL;
	str_len = parse_float_flag2(data, num_len);
	if (str_len < 0)
		str_len = 0;
	if (str_len >= 0)
	{
		if (!(str_flag = (char *)malloc(sizeof(char) * (str_len + 1))))
			return (NULL);
	}
	else
		return (NULL);
	str_flag[str_len] = '\0';
	while (i < str_len)
		if (data->f_zro == 1)
			str_flag[i++] = '0';
		else
			str_flag[i++] = ' ';
	return (str_flag);
}
