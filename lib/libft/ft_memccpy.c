/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:15:17 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 15:50:33 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	if (d == s)
		return ((void*)src);
	if (!d && !s)
		return (NULL);
	while (n != 0)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			return ((void*)(d + 1));
		}
		s++;
		d++;
		n--;
	}
	return (NULL);
}
