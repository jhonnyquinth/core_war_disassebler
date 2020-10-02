/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:54:20 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 20:44:04 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
		}
		else if (to_find[j] == '\0')
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
