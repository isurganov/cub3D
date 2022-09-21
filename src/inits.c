/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:51:09 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/21 13:58:35 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_init_data(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img.img = NULL;
	game->img.addr = NULL;
	game->map.map = NULL;
	game->map.north_sprite = NULL;
	game->map.south_sprite = NULL;
	game->map.west_sprite = NULL;
	game->map.east_sprite = NULL;
	game->map.ceiling = -1;
	game->map.floor = -1;
}

void	ft_init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub_3D");
	game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_length,
			&game->img.endian);
}

void	ft_init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, KEY_WIN_CROSS, 0, exit_hook, game);
}
