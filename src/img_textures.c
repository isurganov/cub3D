/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   img_textures.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ilya <ilya@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/23 13:56:44 by ilya			  #+#	#+#			 */
/*   Updated: 2022/09/25 15:41:35 by ilya			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	tex_calculations(t_game *game)
{
	double	wall_x;

	if (game->ray.side == 0)
		wall_x = game->pl.pos.y + game->ray.wall_dist * game->ray.ray_dir.y;
	else
		wall_x = game->pl.pos.x + game->ray.wall_dist * game->ray.ray_dir.x;
	wall_x -= floor(wall_x);
	game->wall.tex_x = (int)(wall_x * (double)(T_WIDTH));
	if (game->ray.side == 0 && game->ray.ray_dir.x > 0)
		game->wall.tex_x = T_WIDTH - game->wall.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir.y < 0)
		game->wall.tex_x = T_WIDTH - game->wall.tex_x - 1;
	game->wall.step = 1.0 * T_WIDTH / game->ray.line_height;
	game->wall.tex_pos = (game->ray.start - WIN_HEIGHT / 2
			+ game->ray.line_height / 2) * game->wall.step;
}

static int	texture_dot(t_game *game, int *color)
{
	*color = 0;
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir.x >= 0)
			*color = ((unsigned int *)(game->map.east_sprite))
			[T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
		else
			*color = ((unsigned int *)(game->map.west_sprite))
			[T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
	}
	if (game->ray.side == 1)
	{
		if (game->ray.ray_dir.y >= 0)
			*color = ((unsigned int *)(game->map.south_sprite))
			[T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
		else
			*color = ((unsigned int *)(game->map.north_sprite))
			[T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
	}
	return (*color);
}

void	textures(t_game *game, int x)
{
	int				y;
	int				color;

	tex_calculations(game);
	y = game->ray.start;
	while (y <= game->ray.end)
	{
		game->wall.tex_y = (int)game->wall.tex_pos & (T_HEIGHT - 1);
		game->wall.tex_pos += game->wall.step;
		color = texture_dot(game, &color);
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}
