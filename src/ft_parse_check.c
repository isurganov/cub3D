/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:06:29 by ilya              #+#    #+#             */
/*   Updated: 2022/09/25 17:47:43 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	set_position(t_game *game, int view, double i, double j)
{
	game->pl.pos.x = j;
	game->pl.pos.y = i;
	if (view == 'N')
	{
		game->pl.dir.y = -1;
		game->ray.plane.x = 0.66;
	}
	else if (view == 'S')
	{
		game->pl.dir.y = 1;
		game->ray.plane.x = -0.66;
	}
	else if (view == 'W')
	{
		game->pl.dir.x = -1;
		game->ray.plane.y = -0.66;
	}
	else if (view == 'E')
	{
		game->pl.dir.x = 1;
		game->ray.plane.y = 0.66;
	}
}

static void	ft_check_player(t_game *game)
{
	double	i;
	double	j;
	int		count;
	int		player;

	count = 0;
	i = -1;
	while (game->map.map[(int)++i])
	{
		j = -1;
		while (game->map.map[(int)i][(int)++j])
		{
			player = (int)game->map.map[(int)i][(int)j];
			if (ft_strchr("NSWE", player))
			{
				count++;
				if (count == 2)
					ft_mistake("Found more than one player\n");
				set_position(game, player, i, j);
				game->map.map[(int)i][(int)j] = '0';
			}
		}
	}
	if (count == 0)
		ft_mistake("Found 0 players\n");
}

void	ft_checker(t_game *game)
{
	if (game->map.height == 0)
		ft_mistake(EMPTY_MAP);
	if (game->map.north_sprite == NULL
		|| game->map.south_sprite == NULL
		|| game->map.west_sprite == NULL
		|| game->map.east_sprite == NULL)
		ft_mistake(BAD_LOAD_NSWE);
	if (game->map.floor == -1
		|| game->map.ceiling == -1)
		ft_mistake(BAD_LOAD_FC);
	ft_check_player(game);
	ft_check_close_map(game);
}
