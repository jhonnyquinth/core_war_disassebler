/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:31:43 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 22:48:47 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

unsigned int	to_code_len(char buff_n[CODE_LEN], int i)
{
	int			idx;
	unsigned	code_len;

	idx = i;
	code_len = 0;
	while (--idx >= 0)
		code_len |= (unsigned)buff_n[idx] << (i - idx - 1) * 8;
	return (code_len);
}

void			add_chr(t_cmd *acmd, char s)
{
	char *tmp;
	char c[2];

	tmp = acmd->str;
	c[0] = s;
	c[1] = '\0';
	acmd->str = ft_strjoin(tmp, c);
	free(tmp);
}

void			add_str(t_cmd *acmd, char *s)
{
	char *tmp;

	tmp = acmd->str;
	acmd->str = ft_strjoin(tmp, s);
	free(tmp);
}
