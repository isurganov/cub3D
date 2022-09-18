/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:46:08 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/18 16:53:11 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define BLUE   "\033[0;34m"
# define YELW   "\033[1;33m"
# define WTH    "\033[0;37m"

# define BAD_ARGS "Use: ./cub3d MAP_NAME.cub\n"
# define BAD_EXTS "Extension must be .cub\n"
# define BAD_FILE "Cannot open the file\n"

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_M				46
# define KEY_SPACE			49
# define KEY_ENTER			36
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define WIN_WIDTH  800  // 1280 // 1920
# define WIN_HEIGHT 400 // 720 // 1080
// # define T_WIDTH 64
// # define T_HEIGHT 64
// # define RS 0.20
// # define MS 0.25

# define PI				3.14159265
# define TWO_PI			6.28316530

typedef struct s_game
{
    void	        *mlx;
	void	        *win;
}   t_game;

//  fts_errors.c //
int     ft_mistake(char *arg);

//  ft_parcer.c //
void    ft_parcer(t_game *game, int file_descriptor);

//  cub_3D.c //
void    ft_cub3D(t_game *game, char **argv);

#endif