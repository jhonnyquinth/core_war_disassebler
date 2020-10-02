/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:19:40 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 17:06:11 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skip_spaces(const char *s, int *i)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
	}
	*i = 0;
	return (s);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	int		last;
	char	*str;

	last = 0;
	if (!s)
		return (0);
	s = ft_skip_spaces(s, &i);
	while (s[i + 1])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			if (s[i + 1] == ' ' || s[i + 1] == '\n' || s[i + 1] == '\t')
				last = i;
		i++;
	}
	if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i + 1] == '\0')
		last = i;
	if (!(str = ft_strnew(last + 1)))
		return (NULL);
	i = -1;
	while (++i <= last)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
