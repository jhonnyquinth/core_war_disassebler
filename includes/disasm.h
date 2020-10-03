/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 23:09:46 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 23:11:17 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H
# define BUFF_S 1
# define MAGIC_HEADER 4
# define NAME 128
# define NULL_BYTE 4
# define COMMENT 2048
# define CODE_LEN 4
# include "../lib/includes/header.h"
# include "op.h"

typedef struct		s_asm
{
	char			*name;
	char			*comment;
	char			*code;
	unsigned int	len_code;
}					t_asm;

typedef struct		s_cmd
{
	char			*str;
	char			arg[4];
	char			byte_code[4];
	int				num_bytes[4];
}					t_cmd;

unsigned int		to_code_len(char buff_n[CODE_LEN], int i);
void				add_chr(t_cmd *acmd, char s);
void				add_str(t_cmd *acmd, char *s);
int					reader(char *file_name, t_asm *sasm);
int					read_code(int fd, t_asm *sasm);
t_asm				*init_asm(void);
void				init_cmd(t_cmd *acmd, char cmd);
void				free_asm(t_asm *sasm);
void				writer(t_asm *sasm, char *file_name);
#endif
