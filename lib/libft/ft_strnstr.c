/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:00:59 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/09 20:58:44 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find[j])
		{
			j++;
		}
		else if (j == (n) || to_find[j] == '\0')
		{
			return ((char*)(str) + i - j);
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (to_find[j] == '\0')
		return ((char*)(str) + i - j);
	return (NULL);
}
