/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:35:57 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 23:08:51 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static void	write_to_acmd(t_cmd *acmd, int i, int nb, char arg)
{
	acmd->arg[i] = arg;
	acmd->num_bytes[i] = nb;
}

static int	read_code_arg(char arg, t_cmd *acmd, char cmd)
{
	int				i;
	unsigned int	cmp[3];

	i = 0;
	cmp[0] = 0b11000000;
	cmp[1] = 0b00110000;
	cmp[2] = 0b00001100;
	while (i < g_op_tab[(int)cmd].count_arg)
	{
		if ((arg & cmp[i]) >> (3 - i) * 2 == 1)
			write_to_acmd(acmd, i, 1, 'r');
		else if ((arg & cmp[i]) >> (3 - i) * 2 == 2)
			write_to_acmd(acmd, i, g_op_tab[(int)cmd].dir_size, '%');
		else if ((arg & cmp[i]) >> (3 - i) * 2 == 3)
			write_to_acmd(acmd, i, 2, 'n');
		else
			return (1);
		i++;
	}
	return (0);
}

static void	add_cmd_str(t_cmd *acmd, int i)
{
	char *tmp;

	tmp = acmd->str;
	if (i != 0)
		tmp = ft_strdup(", ");
	else
		tmp = ft_strdup(" ");
	add_str(acmd, tmp);
	free(tmp);
	tmp = acmd->str;
	if (acmd->arg[i] != 'n')
		add_chr(acmd, acmd->arg[i]);
	tmp = ft_itoa(to_code_len(acmd->byte_code, acmd->num_bytes[i]));
	add_str(acmd, tmp);
	free(tmp);
}

static char	*read_code_cmd(int fd)
{
	char	cmd[2];
	char	arg[2];
	t_cmd	c;
	int		i;

	i = 0;
	cmd[1] = '\0';
	arg[1] = '\0';
	if (read(fd, cmd, 1) != 1)
		return (NULL);
	init_cmd(&c, *cmd);
	if (g_op_tab[(int)(*cmd) - 1].have_arg_code)
		if (read(fd, arg, 1) != 1 || read_code_arg(*arg, &c, *cmd - 1))
			return (NULL);
	while (c.arg[i])
	{
		if (read(fd, c.byte_code, c.num_bytes[i]) != c.num_bytes[i])
			return (NULL);
		add_cmd_str(&c, i);
		i++;
	}
	cmd[0] = '\n';
	add_str(&c, cmd);
	return (c.str);
}

int			read_code(int fd, t_asm *sasm)
{
	char	buff_n[NULL_BYTE];
	char	*tmp;
	char	*tmp_g;

	if (read(fd, buff_n, NULL_BYTE) != NULL_BYTE)
		return (1);
	while ((tmp = read_code_cmd(fd)))
	{
		tmp_g = sasm->code ? sasm->code : ft_strdup("\n");
		sasm->code = ft_strjoin(tmp_g, tmp);
		free(tmp);
		free(tmp_g);
	}
	return (0);
}
