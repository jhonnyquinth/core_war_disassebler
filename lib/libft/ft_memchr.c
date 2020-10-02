/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:30:15 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/07 18:49:00 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	const char *s;

	s = (const char*)str;
	while (n != 0)
	{
		if (*s == (char)ch)
			return ((void*)(s));
		s++;
		n--;
	}
	return (NULL);
}
