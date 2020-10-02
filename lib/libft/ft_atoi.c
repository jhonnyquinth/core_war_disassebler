/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:20:46 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/18 22:11:50 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_help(const char *str, long int *n, int *m_flag, int *zero_flag)
{
	if (*str == '\n' || *str == ' ' || *str == '\t')
		*m_flag = *m_flag + 1 - 1;
	else if (*str == '\v' || *str == '\f' || *str == '\r')
		*m_flag = *m_flag + 1 - 1;
	else if (*str == '+' || *str == '-')
	{
		if (*(str + 1) >= '0' && *(str + 1) <= '9')
		{
			if (*str == '-')
				*m_flag = -1;
		}
		else
			*zero_flag = 0;
	}
	else if (*str >= '0' && *str <= '9')
		*n = *n * 10 + *str - '0';
	else
		*zero_flag = 0;
}

int			ft_atoi(const char *str)
{
	long int	n;
	int			m_flag;
	int			zero_flag;

	m_flag = 1;
	zero_flag = 1;
	n = 0;
	while (*str == '0')
		if (*(str + 1) < '0' || *(str++ + 1) > '9')
			return (0);
	while (*str != '\0')
	{
		if (n == 0)
			ft_help(str, &n, &m_flag, &zero_flag);
		else if (n < 0)
			return (m_flag == 1 ? -1 : 0);
		else if (*str >= '0' && *str <= '9')
			n = n * 10 + *str - '0';
		else
			return (n * m_flag * zero_flag);
		str++;
	}
	return (n * m_flag * zero_flag);
}
