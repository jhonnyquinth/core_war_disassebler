/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:01:33 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 18:05:14 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	l;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (!(str = ft_strnew(l)) || !f)
		return (NULL);
	while (i < l)
	{
		str[i] = (*f)(i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
