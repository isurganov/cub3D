# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 11:52:31 by pleoma            #+#    #+#              #
#    Updated: 2022/09/18 15:47:50 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRC			=	main.c \
				fts_errors.c \
				ft_parcer.c \
				cub3D.c \

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
		leaks --atExit -- ./$(NAME)

.PHONY			: all clean fclean re

#-include $(DEP_PATH)
