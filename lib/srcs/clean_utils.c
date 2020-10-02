/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:07:07 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:07 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_mult(t_mult *m)
{
	m->len1 = 0;
	m->len2 = 0;
	ft_strdel(&(m->str1));
	ft_strdel(&(m->str2));
}

char	*make_new_str(char *new_str, char *str)
{
	char one[2];

	one[0] = '1';
	one[1] = '\0';
	new_str = ft_strjoin(one, str);
	ft_strdel(&str);
	return (new_str);
}
