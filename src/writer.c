/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:40:30 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 22:50:51 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static char	*create_filename(char *s)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (!(new_s = (char*)malloc(sizeof(char) * (i + 3))))
		return (NULL);
	new_s[i] = '.';
	new_s[i + 1] = 's';
	new_s[i + 2] = '\0';
	while (--i >= 0)
		new_s[i] = s[i];
	return (new_s);
}

void		writer(t_asm *sasm, char *file_name)
{
	int		fd;
	char	*s;

	s = create_filename(file_name);
	fd = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	free(s);
	if (!fd)
	{
		free_asm(sasm);
		ft_putstr("Error\n");
		exit(0);
	}
	ft_putstr_fd(".name \"", fd);
	ft_putstr_fd(sasm->name, fd);
	ft_putstr_fd("\"\n.comment \"", fd);
	ft_putstr_fd(sasm->comment, fd);
	ft_putstr_fd("\"\n", fd);
	ft_putstr_fd(sasm->code, fd);
}
