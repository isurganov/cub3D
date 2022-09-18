/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:33:51 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/18 16:57:24 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void init_game_win(t_game *game)
{
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT,"Cub_3D");
}

static int     ft_open_file(char **argv)
{
    int file_descriptor;

    file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor < 0)
		return (ft_mistake(BAD_FILE));
    return (file_descriptor);
}

void ft_cub3D(t_game *game, char **argv)
{
    //ft_init_data();
    init_game_win(game);
    // init_game_hooks();
    ft_parcer(game, ft_open_file(argv));
    // loop_hook();
    mlx_loop(game->mlx);
    return ;
}