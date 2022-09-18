/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:33:51 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/14 12:42:57 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void init_game_win(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        ft_mistake("Can not init mlx");
	game->mlx_win = mlx_new_window(game->mlx,
        game->win_resolution_x,
        game->win_resolution_y,
        "Cub_3D");
    if(!game->mlx_win)
        ft_mistake("Can not create mlx_new_window");
}

static void init_game_info(t_game *game)
{
    // NOT FINISHED
    game->win_resolution_x = 800;
	game->win_resolution_y = 400;
}


void ft_cub3D(const char *map, int fd)
{
    t_game  game;

    printf("map :%s\n",   map); //no
    printf("fd :%i\n",    fd);  //no
    init_game_info(&game);
    //init_alloc_game(&game);
    //parse_map;

    init_game_win(&game);
    
    mlx_loop(game.mlx);

    return ;
}