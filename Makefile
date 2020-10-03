
NAME = disasm

SRC_DIR	:= ./src
LIB_DIR	:= ./lib
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj

SRC		:=	main.c \
			reader.c \
			reader_code.c \
			writer.c \
			utils.c \
			utils_struct.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

L_FT	:= $(LIB_DIR)/
LIB_LNK := $(LIB_DIR)/libftprintf.a

all:
	@$(MAKE) -C $(L_FT)
	@$(MAKE) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) -g $(CFLAGS) -I $(INC_DIR) $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) -g $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

relibs:
	@$(MAKE) -C $(L_FT) re
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re relibs