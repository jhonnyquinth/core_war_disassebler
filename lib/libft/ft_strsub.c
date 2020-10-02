/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:16:01 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/10 19:16:15 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL || !(str = ft_strnew(len)))
		return (NULL);
	while (i != len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
