/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:29 by ilya              #+#    #+#             */
/*   Updated: 2022/09/22 21:12:07 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void ft_check_player(t_game *game)
{
    
}

void ft_checker(t_game *game)
{
    if (game->map.height == 0)
		ft_mistake("Empty map\n");
    if (game->map.north_sprite == NULL ||
        game->map.south_sprite == NULL ||
        game->map.west_sprite == NULL ||
        game->map.east_sprite == NULL)
        ft_mistake(BAD_LOAD_NSWE);
    if (game->map.floor == -1 ||
        game->map.ceiling == -1)
        ft_mistake(BAD_LOAD_FC);
    //ft_check_player(game);
    ft_check_close_map(game);
} 