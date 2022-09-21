/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:46:08 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/21 13:13:54 by ilya             ###   ########.fr       */
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

# define BAD_ARGS 		"Use: ./cub3d MAP_NAME.cub\n"
# define BAD_EXTS 		"Extension must be .cub\n"
# define BAD_FILE 		"Cannot open the file\n"
# define BAD_SPR		"Cannot get texture addres\n"
# define BAD_SPR_NAME	"Wrong name of texture\n"
# define BAD_XPM		"wrong xpm file\n"
# define BAD_LOAD_NSWE	"NWES didn't load\n"
# define BAD_LOAD_FC	"FC didn't load\n"

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_M				46
# define KEY_SPACE			49
# define KEY_ENTER			36
# define KEY_ESC 			53
# define KEY_W 				13
# define KEY_A 				0
# define KEY_S 				1
# define KEY_D 				2
# define KEY_WIN_CROSS 		17
# define WIN_WIDTH  800  // 1280 // 1920
# define WIN_HEIGHT 400 // 720 // 1080
# define T_WIDTH 64
# define T_HEIGHT 64
// # define RS 0.20
// # define MS 0.25

# define PI				3.14159265
# define TWO_PI			6.28316530

enum	pos
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_data
{
	void	*img;
	void	*img_t[5];
	char	*addr;
	int		bits_per_pixel;		//bpp
	int		line_length;		//ll
	int		endian;
}	t_data_img;


typedef struct s_map
{
	char	**map;
	char	*north_sprite;
	char	*south_sprite;
	char	*west_sprite;
	char	*east_sprite;
    int		floor;      //color code
	int		ceiling;    //color code
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;

	t_data_img		img;
    t_map           map;
}   t_game;

//  fts_errors.c //
int     ft_mistake(char *arg);

//  ft_parcer.c //
void	draw_floor_ceiling(t_game *game);
void	ft_parcer(t_game *game, int file_descriptor);

//	ft_parce_walls.c //
void	ft_pars_walls(char *line, t_game *game);

//	ft_parce_check.c //
void ft_checker(t_game *game);

//  cub_3D.c //
void	ft_cub3D(t_game *game, char **argv);

//  inits.c //
void	ft_init_data(t_game *game);
void	ft_init_win(t_game *game);
void	ft_init_hooks(t_game *game);

//  stert_draw.c //
void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color);
void	draw_floor_ceiling(t_game *game);
int		render_next_frame(t_game *game);

//	hook_keys.c //
int		exit_hook(t_game *game);
int		key_hook(int key, t_game *game);

#endif