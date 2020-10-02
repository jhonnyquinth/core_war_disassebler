/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:42:55 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 18:04:31 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	l;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (!(str = ft_strnew(l)))
		return (NULL);
	while (i < l)
	{
		str[i] = (*f)((char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
