/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:19:40 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 23:40:52 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_lenwrd(const char *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static size_t			ft_cntwrd(const char *s, char c)
{
	size_t cnt;

	if (*s == c || *s == '\0')
		cnt = 0;
	else
		cnt = 1;
	while (*(s + 1) && *s)
	{
		if (*s == c && *(s + 1) != c)
			cnt++;
		s++;
	}
	return (cnt);
}

static char				*ft_strs(char const *s, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL || !(str = ft_strnew(len + 1)))
		return (NULL);
	while (i != len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void				ft_super_free(char **arr_head, char **arr)
{
	while (arr_head != arr--)
		free(*arr);
	free(arr);
}

char					**ft_strsplit(char const *s, char c)
{
	size_t	len;
	size_t	wlen;
	char	**arr;
	char	**arr_head;

	if (!s || !c)
		return (NULL);
	wlen = ft_cntwrd(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (wlen + 1))))
		return (NULL);
	arr_head = arr;
	while (wlen--)
	{
		while (*s == c)
			s++;
		len = ft_lenwrd(s, c);
		if (!(*arr++ = ft_strs(s, len)))
		{
			ft_super_free(arr_head, arr);
			return (NULL);
		}
		s += len;
	}
	*arr = NULL;
	return (arr_head);
}
