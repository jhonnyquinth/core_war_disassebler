#include "disasm.h"

t_asm	*init_asm(void)
{
	t_asm	*sasm;

	if (!(sasm = (t_asm*)malloc(sizeof(t_asm))))
		return NULL;
	sasm->name = NULL;
	sasm->comment = NULL;
	sasm->code = NULL;
	sasm->len_code = 0;
	return sasm;
}

int	read_name(int	fd, t_asm *sasm)
{
	char	buff_m[MAGIC_HEADER];
	char	buff_name[NAME+1];

	if (read(fd, buff_m, MAGIC_HEADER) !=  MAGIC_HEADER)
		return (1);
	if (read(fd, buff_name, NAME) !=  NAME)
		return (1);
	buff_name[NAME] = '\0';
	sasm->name = ft_strdup(buff_name);
	return (0);
}

unsigned int	to_code_len(char buff_n[CODE_LEN])
{
	int	idx;
	unsigned code_len;

	idx = 0;
	code_len = 0;
	while(idx < CODE_LEN)
	{
		code_len |= (unsigned)buff_n[idx] << idx*8;
		idx++;
	}
	return code_len;
}

int	read_comment(int fd, t_asm *sasm)
{
	char	buff_n[NULL_BYTE];
	char	buff_comment[COMMENT+1];

	if (read(fd, buff_n, NULL_BYTE) !=  NULL_BYTE)
		return (1);
	if (read(fd, buff_n, CODE_LEN) !=  CODE_LEN)
		return (1);
	sasm->len_code = to_code_len(buff_n);
	if (read(fd, buff_comment, COMMENT) !=  COMMENT)
		return (1);
	sasm->comment = ft_strdup(buff_comment);
	return (0);
}

int	reader(char *file_name, t_asm *sasm)
{
	int fd;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (1);
	if(read_name(fd, sasm))
		return (1);
	// sasm->comment = read_comment(fd, sasm);
	// sasm->code = read_code(fd);

	return (0);
}

int	main(int ac, char **av)
{
	t_asm *sasm;

	sasm = NULL;
	if (ac > 2)
	{
		sasm = init_asm();
		if(reader(av[1], sasm))
			return (1);
	}
	ft_printf("%s\n",sasm->name);
	return (0);
}