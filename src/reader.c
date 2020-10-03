/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:34:20 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 22:58:10 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static int	check_name(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (!s[i] || s[i + 1] != 'c' || s[i + 2] != 'o' ||\
	s[i + 3] != 'r' || s[i + 4])
		return (1);
	return (0);
}

static int	read_name(int fd, t_asm *sasm)
{
	char	buff_m[MAGIC_HEADER];
	char	buff_name[NAME + 1];

	if (read(fd, buff_m, MAGIC_HEADER) != MAGIC_HEADER)
		return (1);
	if (read(fd, buff_name, NAME) != NAME)
		return (1);
	buff_name[NAME] = '\0';
	sasm->name = ft_strdup(buff_name);
	return (0);
}

static int	read_comment(int fd, t_asm *sasm)
{
	char	buff_n[NULL_BYTE];
	char	buff_comment[COMMENT + 1];

	if (read(fd, buff_n, NULL_BYTE) != NULL_BYTE)
		return (1);
	if (read(fd, buff_n, CODE_LEN) != CODE_LEN)
		return (1);
	sasm->len_code = to_code_len(buff_n, CODE_LEN);
	if (read(fd, buff_comment, COMMENT) != COMMENT)
		return (1);
	sasm->comment = ft_strdup(buff_comment);
	return (0);
}

int			reader(char *file_name, t_asm *sasm)
{
	int fd;

	if (check_name(file_name))
		return (1);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (1);
	if (read_name(fd, sasm) || read_comment(fd, sasm) || read_code(fd, sasm))
		return (1);
	return (0);
}
