/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:11:24 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 16:42:06 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (d <= s)
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	else
	{
		i = n - 1;
		while (n--)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
