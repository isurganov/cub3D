/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:43:11 by ilya              #+#    #+#             */
/*   Updated: 2022/09/25 17:10:44 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	hook_w(t_game *game)
{
	if (game->map.map[(int)(game->pl.pos.y)]
        [(int)(game->pl.pos.x + game->pl.dir.x * COEF_STEP)] == '0')
		game->pl.pos.x += game->pl.dir.x * COEF_STEP;
	if (game->map.map[(int)(game->pl.pos.y + game->pl.dir.y * COEF_STEP)]
		[(int)(game->pl.pos.x)] == '0')
		game->pl.pos.y += game->pl.dir.y * COEF_STEP;
}

void	hook_s(t_game *game)
{
	if (game->map.map[(int)(game->pl.pos.y)]
		[(int)(game->pl.pos.x - game->pl.dir.x * COEF_STEP)] == '0')
		game->pl.pos.x -= game->pl.dir.x * COEF_STEP;
	if (game->map.map[(int)(game->pl.pos.y - game->pl.dir.y * COEF_STEP)]
		[(int)(game->pl.pos.x)] == '0')
		game->pl.pos.y -= game->pl.dir.y * COEF_STEP;
}

void	hook_a(t_game *game)
{
	if (game->map.map[(int)(game->pl.pos.y)]
        [(int)(game->pl.pos.x - game->ray.plane.x * COEF_STEP)] == '0')
		game->pl.pos.x -= game->ray.plane.x * COEF_STEP;
	if (game->map.map[(int)(game->pl.pos.y - game->ray.plane.y * COEF_STEP)]
        [(int)(game->pl.pos.x)] == '0')
		game->pl.pos.y -= game->ray.plane.y * COEF_STEP;
}

void	hook_d(t_game *game)
{
	if (game->map.map[(int)(game->pl.pos.y)]
		[(int)(game->pl.pos.x + game->ray.plane.x * COEF_STEP)] == '0')
		game->pl.pos.x += game->ray.plane.x * COEF_STEP;
	if (game->map.map[(int)(game->pl.pos.y + game->ray.plane.y * COEF_STEP)]
		[(int)(game->pl.pos.x)] == '0')
		game->pl.pos.y += game->ray.plane.y * COEF_STEP;
}