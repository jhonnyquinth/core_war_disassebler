/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:50 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 06:41:58 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*parse_float_number(long double number, t_persent *data)
{
	t_cast		d1;
	char		*str_exp;
	char		*str_mant;
	char		*str_full;
	int			pow;

	str_full = NULL;
	d1 = (t_cast){ .ld = number};
	pow = (int)d1.t_parts.exponent - 16383;
	if (d1.t_parts.exponent == 32767)
		return (is_nan(d1.t_parts.mantissa, data->modf));
	if (d1.t_parts.exponent == 0)
		return (zero_str(data->precision, data->f_hesh, str_full));
	str_mant = parse_mantis(d1.t_parts.mantissa);
	str_exp = parse_exponent(pow);
	str_full = make_f_str(str_full, &str_mant, &str_exp);
	if (number >= 1 || number <= -1)
		str_full = make_dot(&str_full, d1.t_parts.exponent);
	else
		str_full = make_dot_zero(&str_full);
	str_full = make_full_str(str_full, data->precision, data->f_hesh);
	return (str_full);
}

char	*make_f_str(char *full, char **mantissa, char **exponent)
{
	t_mult		m[1];
	int			k;

	k = 0;
	m->len1 = 0;
	m->len2 = 0;
	m->str1 = NULL;
	m->str2 = NULL;
	if (!(full = (char *)malloc(sizeof(char) * 5000)))
		return (NULL);
	if (ft_strlen(*exponent) < ft_strlen(*mantissa))
		fill_exp_mant(m, exponent, mantissa);
	else
		fill_exp_mant(m, mantissa, exponent);
	while (k < (m->len1 + m->len2))
	{
		full[k] = '0';
		k++;
	}
	full = str_multiplication(m, full);
	clean_mult(m);
	return (full);
}

char	*make_full_str(char *full_str, int precision, int f_hesh)
{
	char		dot[2];

	dot[0] = '.';
	dot[1] = '\0';
	full_str = make_round(&full_str, precision);
	if (full_str[ft_strlen(full_str) - 1] == '.')
		full_str[ft_strlen(full_str) - 1] = '\0';
	if (precision == 0 && f_hesh == 1)
		full_str = ft_strjoin(full_str, dot);
	return (full_str);
}

char	*parse_exponent(int pow)
{
	char		*str;

	if (pow > 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (pow * 0.301 + 1))))
			return (NULL);
		str = pow_two(str, pow);
	}
	else if (pow == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '1';
		str[1] = '\0';
	}
	else
	{
		pow = pow * -1;
		if (!(str = (char *)malloc(sizeof(char) * (pow + 1))))
			return (NULL);
		ft_bzero(str, pow - 1);
		str = pow_five(str, pow);
	}
	return (str);
}

int		parse_float(t_persent *data, long double f)
{
	size_t		len_num;
	size_t		len_flag;
	char		*str_num;
	char		*str_flag;

	str_flag = NULL;
	str_num = NULL;
	casting_float(data, &f);
	if (data->precision < 0)
		data->precision = 6;
	if (data->width < 0)
		data->width = 1;
	str_num = parse_float_number(f, data);
	len_num = ft_strlen(str_num);
	pars_nan_inf(data, str_num[0]);
	str_flag = parse_float_flag(data, len_num);
	len_flag = ft_strlen(str_flag);
	record_float(data, &str_flag, &str_num);
	return (len_num + len_flag + (data->sign | data->f_pls) + data->f_sps);
}
