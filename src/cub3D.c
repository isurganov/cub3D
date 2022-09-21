/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:33:51 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/21 13:01:58 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
    ft_init_data(game);
    ft_init_win(game);
    ft_init_hooks(game);
    ft_parcer(game, ft_open_file(argv));
    mlx_loop_hook(game->mlx, render_next_frame, game);
    mlx_loop(game->mlx);
    return ;
}