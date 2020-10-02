# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 16:28:43 by sbrynn            #+#    #+#              #
#    Updated: 2020/08/07 08:20:47 by sbrynn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/
FT_LIB = $(addprefix $(LIBFT),libft.a)
FT_INK = -I ./libft
FT_LNK = -L ./libft -lft

DIR_S = ./srcs/
DIR_O = ./obj/
HEADER = ./includes/

SOURCES = help.c \
			list.c \
			prinf.c \
			sub_poc.c \
			type_functions.c \
			casting_float.c \
			clean_utils.c \
			long_m_str.c \
			make_mantissa.c \
			nan_inf.c \
			pars.c \
			pars_flag.c \
			pars_mantis.c \
			record_float.c \
			str_multiplication.c \
			zero_str.c \
			ints.c \
			hex.c \
			hex_ox.c \
			hex_ox_o.c \
			helps2.c \
			printf_help.c \
			

OBJS = $(addprefix $(DIR_O),$(SOURCES:.c=.o))

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(DIR_O)
$(DIR_O)%.o:$(DIR_S)%.c
	@$(CC) $(FLAGS) $(FT_INK) -I $(HEADER) -o $@ -c $<

$(FT_LIB):
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re all clean
