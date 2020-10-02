/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:02:30 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/07 14:48:33 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int ch)
{
	const char *s;

	s = NULL;
	while (*str)
	{
		if (*str == ch)
			s = str;
		str++;
	}
	if (*str == ch)
		s = str;
	return ((char*)(s));
}
