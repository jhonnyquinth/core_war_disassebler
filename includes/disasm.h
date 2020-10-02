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
#endif