/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:18:17 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 21:20:10 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	len;

	len = 0;
	while (*dest != '\0')
	{
		if (nb != 0)
		{
			len++;
			nb--;
		}
		dest++;
	}
	while (*src != '\0')
	{
		if (nb > 1)
		{
			*dest = *src;
			dest++;
			nb--;
		}
		src++;
		len++;
	}
	*dest = '\0';
	return (len);
}
