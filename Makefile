# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 11:52:31 by pleoma            #+#    #+#              #
#    Updated: 2022/09/04 22:41:46 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRC			=	main.c \
				fts_errors.c \
				check_arg.c \

OBJDIR		=	obj
SRCDIR		=	src

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

$(NAME) 		: $(MINILIBX) $(OBJ_PATH) Makefile
		$(CC) $(FLAGS) $(O_FLAG) -o $(NAME) $(OBJ_PATH) $(MLX_FLAG)

$(OBJDIR)/%.o 	: $(SRCDIR)/%.c $(INC_PATH) Makefile
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) $(O_FLAG) -o $@ -c $<

$(MINILIBX)		:
		make -C minilibx

clean			:
		@rm -rf $(OBJDIR)
		@rm -f	libmlx.a
		@make -C minilibx clean
		@echo "Removing obj"

fclean			:	clean
		@rm -f $(NAME)
		@echo "Removing all"

re				:  fclean all

test			:	$(NAME)
		leaks --atExit -- ./$(NAME)

.PHONY			: all clean fclean re

#-include $(DEP_PATH)
