/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:51:09 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/18 18:46:21 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void ft_init_data(t_game *game)
{
    game->map.map = NULL;
    game->map.ceiling = 5555;   //-1
	game->map.floor = 8547;     //-1
    // ...
}

void ft_init_win(t_game *game)
{
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT,"Cub_3D");
}