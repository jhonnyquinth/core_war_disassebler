/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:49:40 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:55 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*zero_str(int precision, int f_hesh, char *full_str)
{
	int		i;

	i = 2;
	if (precision == 0)
		return (no_precision(f_hesh));
	if (!(full_str = (char *)malloc(sizeof(char) * (precision + 2))))
		return (NULL);
	full_str[0] = '0';
	full_str[1] = '.';
	while (i < (precision + 2))
	{
		full_str[i] = '0';
		i++;
	}
	full_str[i] = '\0';
	return (full_str);
}

char	*no_precision(int f_hesh)
{
	char	*full_str;

	full_str = NULL;
	if (f_hesh)
	{
		if (!(full_str = (char *)malloc(sizeof(char) * 3)))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '.';
		full_str[2] = '\0';
	}
	else
	{
		if (!(full_str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		full_str[0] = '0';
		full_str[1] = '\0';
	}
	return (full_str);
}
