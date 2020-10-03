/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:38:41 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 22:49:31 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_asm	*init_asm(void)
{
	t_asm	*sasm;

	if (!(sasm = (t_asm*)malloc(sizeof(t_asm))))
		return (NULL);
	sasm->name = NULL;
	sasm->comment = NULL;
	sasm->code = NULL;
	sasm->len_code = 0;
	return (sasm);
}

void	init_cmd(t_cmd *acmd, char cmd)
{
	int i;

	i = 1;
	acmd->str = ft_strdup(g_op_tab[(int)cmd - 1].name);
	acmd->arg[0] = '%';
	acmd->num_bytes[0] = g_op_tab[(int)cmd].dir_size;
	while (i < 4)
	{
		acmd->arg[i] = 0;
		acmd->byte_code[i] = 0;
		acmd->num_bytes[i] = 0;
		i++;
	}
}

void	free_asm(t_asm *sasm)
{
	free(sasm->name);
	free(sasm->comment);
	free(sasm->code);
	free(sasm);
}
