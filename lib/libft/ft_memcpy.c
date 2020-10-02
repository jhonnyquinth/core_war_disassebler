/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:53:09 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/07 16:14:11 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char *s;

	d = dest;
	s = src;
	if (d == s)
		return ((void*)src);
	while (n != 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}
