/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   img_raycast.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ilya <ilya@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/23 13:03:39 by ilya			  #+#	#+#			 */
/*   Updated: 2022/09/25 18:01:22 by ilya			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	delta_dist(t_game *game, int x)
{
	game->ray.camera_x = ((2.0 * x / (double)(WIN_WIDTH)) - 1.0);
	game->ray.ray_dir.x = game->pl.dir.x
		+ game->ray.plane.x * game->ray.camera_x;
	game->ray.ray_dir.y = game->pl.dir.y
		+ game->ray.plane.y * game->ray.camera_x;
	game->map.x_pl = (int)(game->pl.pos.x);
	game->map.y_pl = (int)(game->pl.pos.y);
	game->ray.dd.x = fabs(1.0 / game->ray.ray_dir.x);
	game->ray.dd.y = fabs(1.0 / game->ray.ray_dir.y);
	game->ray.hit = 0;
}

static void	side_dist(t_game *game)
{
	if (game->ray.ray_dir.x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sd.x = (game->pl.pos.x - game->map.x_pl)
			* game->ray.dd.x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sd.x = (game->map.x_pl + 1.0 - game->pl.pos.x)
			* game->ray.dd.x;
	}
	if (game->ray.ray_dir.y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sd.y = (game->pl.pos.y - game->map.y_pl)
			* game->ray.dd.y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sd.y = (game->map.y_pl + 1.0 - game->pl.pos.y)
			* game->ray.dd.y;
	}
}

static void	dda_algo(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sd.x < game->ray.sd.y)
		{
			game->ray.sd.x += game->ray.dd.x;
			game->map.x_pl += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sd.y += game->ray.dd.y;
			game->map.y_pl += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[(int)(game->map.y_pl)][(int)(game->map.x_pl)] == '1')
			game->ray.hit = 1;
	}
}

static void	calculate_dist(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.wall_dist = (game->ray.sd.x - game->ray.dd.x);
	else
		game->ray.wall_dist = (game->ray.sd.y - game->ray.dd.y);
	game->ray.line_height = (int)(WIN_HEIGHT / game->ray.wall_dist);
	game->ray.start = (-(game->ray.line_height) / 2 + WIN_HEIGHT / 2);
	if (game->ray.start < 0)
		game->ray.start = 0;
	game->ray.end = (game->ray.line_height / 2 + WIN_HEIGHT / 2);
	if (game->ray.end >= WIN_HEIGHT)
		game->ray.end = (WIN_HEIGHT - 1);
}

void	rays_cast(t_game *game, int x)
{
	delta_dist(game, x);
	side_dist(game);
	dda_algo(game);
	calculate_dist(game);
}
