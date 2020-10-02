/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:27:30 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/05 22:02:51 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*s;
	int		size;

	s = (char *)src;
	size = 1;
	while (*s != '\0')
	{
		s++;
		size++;
	}
	if (!(str = (char*)malloc(size)))
		return (0);
	s = str;
	while (*src != '\0')
	{
		*s = *src;
		s++;
		src++;
	}
	*s = *src;
	return (str);
}
