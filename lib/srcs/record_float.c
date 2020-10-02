/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:01:19 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:44 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	out_float(t_persent *data, char **str_flag, char **str_num)
{
	int		len_num;
	int		len_flag;

	len_num = ft_strlen(*str_num);
	len_flag = ft_strlen(*str_flag);
	if (data->f_sps && data->f_zro)
		write(1, " ", 1);
	if ((data->sign || data->f_pls) && data->f_zro)
		(data->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
	if (*str_flag)
		write(1, *str_flag, len_flag);
	if (data->f_sps && !data->f_zro)
		write(1, " ", 1);
	if ((data->sign || data->f_pls) && !data->f_zro)
		(data->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
	if (*str_num)
		write(1, *str_num, len_num);
}

void	out_float_minus(t_persent *data, char **str_flag, char **str_num)
{
	int		len_num;
	int		len_flag;

	len_num = ft_strlen(*str_num);
	len_flag = ft_strlen(*str_flag);
	if (data->f_sps)
		write(1, " ", 1);
	if (data->sign || data->f_pls)
		(data->sign) ? (write(1, "-", 1)) : (write(1, "+", 1));
	if (*str_num)
		write(1, *str_num, len_num);
	if (*str_flag)
		write(1, *str_flag, len_flag);
}

void	record_float(t_persent *data, char **str_flag, char **str_num)
{
	if (data->f_mns == 0)
		out_float(data, str_flag, str_num);
	else if (data->f_mns == 1)
		out_float_minus(data, str_flag, str_num);
	ft_strdel(str_flag);
	ft_strdel(str_num);
}
