# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 09:17:51 by amiguez           #+#    #+#              #
#    Updated: 2023/03/03 11:02:39 by loumarti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := cub3d

# ############################################################################ #
DIR_SRCS	:= srcs
DIR_OBJS	:= .objs
DIR_INCS	:= includes
DIR_LIBFT	:= libft
DIR_MLX		:= mlx_linux
# ############################################################################ #
LST_SRCS	:=	main.c\
				debug.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	cub3d.h\
				debug.h\
				pars_cub.h\
				render.h\
				key.h\
				raycasting.h\
				d_vector.h\
				i_vector.h

PARS		:=	error.c\
				pars.c\
				pars_file.c\
				pars_content.c\
				pars_utiles.c\
				pars_map.c\
				pars_mlx.c
DIR_PARS	:=	pars_map
LST_PARS	:=	$(addprefix $(DIR_PARS)/,$(PARS))
SRC_PARS	:=	$(addprefix $(DIR_SRCS)/,$(LST_PARS))
OBJ_PARS	:=	$(addprefix $(DIR_OBJS)/,$(LST_PARS:.c=.o))

RENDER		:=	loop.c\
				h_key.c\
				h_mouse.c\
				render.c\
				move.c\
				utils.c\
				mini_map.c
DIR_RENDER	:=	render
LST_RENDER	:=	$(addprefix $(DIR_RENDER)/,$(RENDER))
SRC_RENDER	:=	$(addprefix $(DIR_SRCS)/,$(LST_RENDER))
OBJ_RENDER	:=	$(addprefix $(DIR_OBJS)/,$(LST_RENDER:.c=.o))

RAYC		:=	ft_putwall.c\
				cast_a_ray.c\
				ray_tool.c\
				dvect_tool.c\
				ivect_tool.c
DIR_RAYC	:=	raycasting
LST_RAYC	:=	$(addprefix $(DIR_RAYC)/,$(RAYC))
SRC_RAYC	:=	$(addprefix $(DIR_SRCS)/,$(LST_RAYC))
OBJ_RAYC	:=	$(addprefix $(DIR_OBJS)/,$(LST_RAYC:.c=.o))


LST_MLX		:=	libmlx.a
LST_LIBFT	:=	libft.a
# ############################################################################ #
SRCS		:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS)) $(SRC_PARS) $(SRC_RENDER) $(SRC_RAYC)
OBJS		:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS)) $(OBJ_PARS) $(OBJ_RENDER) $(OBJ_RAYC)
INCS		:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))
LIBFT		:=	$(addprefix $(DIR_LIBFT)/,$(LST_LIBFT))
MLX			:=	$(addprefix $(DIR_MLX)/,$(LST_MLX))
# DEPH		:=	$(OBJS:=.o=.d)
# -include $(DEPH)
# ############################################################################ #
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror #-g3 -fsanitize=address
# ############################################################################ #
# **************************************************************************** #
ERASE	:=	\033[2K\r
GREY	:=	\033[30m
RED		:=	\033[31m
GREEN	:=	\033[32m
YELLOW	:=	\033[33m
BLUE	:=	\033[34m
PINK	:=	\033[35m
CYAN	:=	\033[36m
WHITE	:=	\033[37m
BOLD	:=	\033[1m
UNDER	:=	\033[4m
SUR		:=	\033[7m
END		:=	\033[0m
# **************************************************************************** #
# ############################################################################ #
all : $(NAME)

$(NAME) : $(OBJS) Makefile $(INCS) $(LIBFT) | $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I$(DIR_INCS) -I$(DIR_MLX) -o $@ $(MLX) -lm -lX11 -lXext
#-lmlx -framework OpenGL -framework AppKit

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_LIBFT) $(DIR_OBJS)
	$(CC) $(CFLAGS) -lm -c $< -o $@ -I$(DIR_INCS) -MMD

$(DIR_OBJS) :
	mkdir -p $(DIR_OBJS)
	mkdir -p $(DIR_OBJS)/$(DIR_PARS)
	mkdir -p $(DIR_OBJS)/$(DIR_RENDER)
	mkdir -p $(DIR_OBJS)/$(DIR_RAYC)

$(DIR_LIBFT) :
	git submodule update --remote --rebase $(DIR_LIBFT)
	printf "$(YELLOW)LIBFT IS UP TO DATE!\n$(END)$(RED)"
	make -sC $(DIR_LIBFT)

$(MLX) :
	make -sC $(DIR_MLX)

clean :
	rm -rf $(DIR_OBJS)
	make -sC $(DIR_LIBFT) clean
	make -sC $(DIR_MLX) clean

fclean :
	rm -f $(NAME)
	rm -rf $(DIR_OBJS)
	make -sC $(DIR_MLX) clean
	make -sC $(DIR_LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re $(DIR_LIBFT) $(MLX)
# .SILENT :