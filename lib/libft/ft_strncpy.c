/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:37:21 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/05 22:43:08 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *dest1;

	dest1 = dest;
	while (n != 0)
	{
		if (*src != '\0')
		{
			*dest1 = *src;
			src++;
		}
		else
		{
			*dest1 = '\0';
		}
		dest1++;
		n--;
	}
	return (dest);
}
