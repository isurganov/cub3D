/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:58:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/22 19:17:34 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	exit_hook(t_game *game)
{
	printf(GREEN "Exit!\n" WTH);
	//mlx_destroy_image(game->mlx, game->img.img);
	//mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map_copy);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_hook(game);
	else if (key == KEY_W)
		printf("KEY");
	else if (key == KEY_S)
		printf("KEY");
	else if (key == KEY_A)
		printf("KEY");
	else if (key == KEY_D)
		printf("KEY");
	else if (key == KEY_LEFT)
		printf("KEY");
	else if (key == KEY_RIGHT)
		printf("KEY");
	return (EXIT_SUCCESS);
}
