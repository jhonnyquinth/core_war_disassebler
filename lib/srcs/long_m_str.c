/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_m_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:30:35 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 05:06:14 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*make_dot(char **str, unsigned short exponent)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1))))
		return (NULL);
	if ((*str)[i] == '0')
		i++;
	while (i <= ((exponent - 16383) * 0.301 + 1))
		tmp[j++] = (*str)[i++];
	tmp[j] = '.';
	j++;
	while ((*str)[i] != '\0')
		tmp[j++] = (*str)[i++];
	tmp[j] = '\0';
	ft_strdel(str);
	return (tmp);
}

char	*make_dot_zero(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 2;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 3))))
		return (NULL);
	ft_bzero(tmp, (ft_strlen(*str) + 3));
	tmp[0] = '0';
	tmp[1] = '.';
	while ((*str)[i] != '\0')
	{
		tmp[j] = (*str)[i];
		i++;
		j++;
	}
	tmp[ft_strlen(*str) + 2] = '\0';
	ft_strdel(str);
	return (tmp);
}

char	*make_round(char **str, int p)
{
	char	*tmp;
	int		tmp_p;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + p + 1))))
		return (NULL);
	tmp_p = p;
	tmp = fill_str(*(str), tmp, p, tmp_p);
	ft_strdel(str);
	return (tmp);
}

char	*fill_str(char *str, char *tmp, int p, int tmp_p)
{
	int		i;
	int		j;
	int		mem;

	i = 0;
	j = 0;
	while (str[i] != '.')
		tmp[i++] = str[j++];
	tmp[i++] = '.';
	j = i;
	while (p-- > -1)
	{
		while (str[j] != '\0' && p-- >= 0)
			tmp[i++] = str[j++];
		tmp[i++] = '0';
	}
	i--;
	if (!((tmp_p == 0) && ((tmp[i - 2] - '0') % 2) == 0 && str[i] <= '5' &&
		!(str[i + 1] >= '5')) && str[i] >= '5')
		mem = 1;
	else
		mem = 0;
	tmp[i] = '\0';
	tmp = rounding(tmp, mem);
	return (tmp);
}

char	*rounding(char *str, int mem)
{
	int		i;
	char	*new_str;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '.')
			i--;
		if (mem == 1 && str[i] >= '0' && str[i] < '9')
		{
			str[i] = ((str[i] - '0') + mem) + '0';
			mem = 0;
			break ;
		}
		else if (mem == 1 && str[i] == '9')
			str[i--] = '0';
		else
			break ;
	}
	new_str = str;
	if (i == -1 && mem == 1)
		new_str = make_new_str(new_str, str);
	return (new_str);
}
