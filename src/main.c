/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:43:54 by sbrynn            #+#    #+#             */
/*   Updated: 2020/10/03 22:50:09 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int	main(int ac, char **av)
{
	t_asm *sasm;

	sasm = NULL;
	if (ac > 1)
	{
		sasm = init_asm();
		if (reader(av[1], sasm))
		{
			ft_putstr("Error\n");
			free_asm(sasm);
			return (1);
		}
		writer(sasm, av[1]);
		free_asm(sasm);
	}
	return (0);
}
