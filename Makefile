# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 07:22:02 by amiguez           #+#    #+#              #
#    Updated: 2023/02/15 07:53:09 by amiguez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d

# **************************************************************************** #
DIR_SRC :=	srcs
DIR_OBJ :=	.objs
DIR_INC :=	includes
# **************************************************************************** #

LST_SRCS :=	main.c
LST_OBJS :=	$(LST_SRCS:.c=.o)
LST_INCS :=	cub3d.h

# **************************************************************************** #
SRCS	:=	$(addprefix $(DIR_SRC)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJ)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INC)/,$(LST_INCS))
# **************************************************************************** #

SRC_MLX	:= libmlx.a
DIR_MLX	:= mlx_linux
MLX		:= $(addprefix $(DIR_MLX)/,$(LST_MLX))

# **************************************************************************** #
ERASE	=	\033[2K\r
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PINK	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m
END		=	\033[0m
# **************************************************************************** #
NORMITEST = 
NORMINETTE = $(shell norminette $(SRCS) | grep -i 'Error!')
# **************************************************************************** #
# /////////////////////////////////
CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra
# /////////////////////////////////

all: $(NAME)

$(NAME): $(OBJS) | $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)
	printf "$(ERASE)Compiling Cub-3D : $(GREEN) Done $(END)\n"

ifeq ($(NORMINETTE),$(NORMITEST))
	printf "$(GREEN)Everything is ok\n$(END)"
else
	printf "$(RED)$(SUR)THERE IS AN ERROR WITH NORMINETTE IN CUB-3D FILES !!\n $(NORMINETTE)$(END)"
endif

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INCS) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@
	printf "$(ERASE)Compiling $(NAME) : $(BLUE) $< $(END)"

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(MLX):
	make -C $(DIR_MLX)

# /////////////////////////////////

clean	:
	rm -rf $(DIR_OBJ)
	printf "$(CYAN) /!\ $(END)Erasing .o in Cub3D$(CYAN) /!\ \n$(END)"
	make -C $(DIR_MLX)

fclean	: clean
	rm -rf $(NAME)
	printf "$(RED) /!\ $(END)Erasing Binary executable$(RED) /!\ \n$(END)"

re		: fclean all

# /////////////////////////////////

.PHONY	: all clean fclean re $(DIR_OBJ)
.SILENT	: