/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:03:22 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:01 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	casting_float(t_persent *data, long double *f)
{
	t_cast	sign_bit;

	if (*f == LDBL_MIN || *f == -LDBL_MIN)
	{
		if (*f == -LDBL_MIN)
			data->sign = 1;
		*f = (long double)0.0;
	}
	if (*f <= 0)
	{
		sign_bit = (t_cast){ .ld = *f};
		if (sign_bit.t_parts.sign & 1)
			data->sign = 1;
		*f = *f * (-1);
	}
}
