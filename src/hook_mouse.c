/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hook_mouse.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ilya <ilya@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/25 16:06:53 by ilya			  #+#	#+#			 */
/*   Updated: 2022/09/25 17:57:56 by ilya			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	hook_left_rotation(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->pl.dir.x;
	old_plane_x = game->ray.plane.x;
	game->pl.dir.x = game->pl.dir.x * cos(-COEF_ROT)
		- game->pl.dir.y * sin(-COEF_ROT);
	game->pl.dir.y = old_dir_x * sin(-COEF_ROT)
		+ game->pl.dir.y * cos(-COEF_ROT);
	game->ray.plane.x = game->ray.plane.x * cos(-COEF_ROT)
		- game->ray.plane.y * sin(-COEF_ROT);
	game->ray.plane.y = old_plane_x * sin(-COEF_ROT)
		+ game->ray.plane.y * cos(-COEF_ROT);
}

void	hook_right_rotation(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->pl.dir.x;
	old_plane_x = game->ray.plane.x;
	game->pl.dir.x = game->pl.dir.x * cos(COEF_ROT)
		- game->pl.dir.y * sin(COEF_ROT);
	game->pl.dir.y = old_dir_x * sin(COEF_ROT)
		+ game->pl.dir.y * cos(COEF_ROT);
	game->ray.plane.x = game->ray.plane.x * cos(COEF_ROT)
		- game->ray.plane.y * sin(COEF_ROT);
	game->ray.plane.y = old_plane_x * sin(COEF_ROT)
		+ game->ray.plane.y * cos(COEF_ROT);
}
