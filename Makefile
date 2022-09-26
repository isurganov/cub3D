# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 11:52:31 by pleoma            #+#    #+#              #
#    Updated: 2022/09/26 13:55:59 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRC			=	main.c \
				fts_errors.c \
				ft_parcer.c \
				ft_parse_walls.c \
				ft_parse_check.c \
				ft_parse_check2.c \
				ft_parse_fc.c \
				ft_parse_map.c \
				cub3D.c \
				inits.c \
				img_draw.c \
				img_raycast.c \
				img_textures.c \
				hook_keys.c \
				hook_wasd.c \
				hook_mouse.c
OBJDIR		=	obj
SRCDIR		=	src

LIBFT		=	libft/libft.a
MINILIBX	=	minilibx/libmlx.a
INC_PATH	= 	includes/cub3D.h
SRC_PATH 	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ_PATH 	=	$(addprefix $(OBJDIR)/, $(notdir $(SRC_PATH:.c=.o)))
#DEP_PATH 	= 	$(addprefix $(OBJDIR)/, $(notdir $(SRC_PATH:.c=.d)))

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
O_FLAG		=	-O3 #-MD
MLX_FLAG	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit -lz

all				: $(NAME)

$(NAME) 		: $(MINILIBX) $(LIBFT) $(OBJ_PATH) Makefile
		$(CC) $(FLAGS) $(O_FLAG) $(OBJ_PATH) $(LIBFT) $(MLX_FLAG) -o $(NAME)

$(OBJDIR)/%.o 	: $(SRCDIR)/%.c $(INC_PATH) Makefile
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) $(O_FLAG) -o $@ -c $<

$(MINILIBX)		:
		@make -C minilibx

$(LIBFT)		:
		@make -C libft

clean			:
		@rm -rf $(OBJDIR)
		@rm -f	libmlx.a
		@make -C minilibx clean
		@make -C libft clean
		@echo "Removing obj"

fclean			:	clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)
		@echo "Removing all"

re				:  fclean all

test			:	$(NAME)
		@echo "Test with wrong map"
		leaks --atExit -- ./cub3D qqq
		@echo "Test with correct map"
		leaks --atExit -- ./cub3D maps/default.cub

.PHONY			: all clean fclean re

#-include $(DEP_PATH)
