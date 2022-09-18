/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:06:47 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/18 18:46:25 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			if (y < WIN_HEIGHT / 2)
				mlx_pixel_put(game->mlx, game->win, x, y, game->map.ceiling);
			else
				mlx_pixel_put(game->mlx, game->win, x, y, game->map.floor);
		}
	}
}

int	game_start(t_game *game)
{
	//NEED OTHER "draw_floor_ceiling"
	//draw_floor_ceiling(game);
	
	return (EXIT_SUCCESS);
}