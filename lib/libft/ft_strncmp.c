/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:30:41 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/07 18:34:35 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1;
	unsigned char c2;

	c1 = *s1;
	c2 = *s2;
	while (c1 == c2 && (c1 != '\0' || c2 != '\0') && n > 1)
	{
		s1++;
		s2++;
		n--;
		c1 = *s1;
		c2 = *s2;
	}
	if (c1 != c2 && n != 0)
		return (c1 - c2);
	else
		return (0);
}
