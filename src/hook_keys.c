/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:58:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/26 13:21:06 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	exit_hook(t_game *game)
{
	printf(RED "Exit!\n" WTH);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map_copy);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_hook(game);
	else if (key == KEY_W)
		hook_w(game);
	else if (key == KEY_S)
		hook_s(game);
	else if (key == KEY_A)
		hook_a(game);
	else if (key == KEY_D)
		hook_d(game);
	else if (key == KEY_LEFT)
		hook_left_rotation(game);
	else if (key == KEY_RIGHT)
		hook_right_rotation(game);
	return (EXIT_SUCCESS);
}
