/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:19:40 by sbrynn            #+#    #+#             */
/*   Updated: 2019/09/10 20:18:35 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (size + 1 == 0)
		return (NULL);
	if (!(s = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
