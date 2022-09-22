/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:36:17 by ilya              #+#    #+#             */
/*   Updated: 2022/09/22 21:10:15 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	check_position(t_game *game, int i, int j)
{
	if (i == 0 || j == 0)
		ft_mistake("Error: invalid map 1\n");
	if (!(game->map.map[i - 1][j]) || !(game->map.map[i][j - 1])
		|| !(game->map.map[i + 1][j]) || !(game->map.map[i][j + 1]))
		ft_mistake("Error: invalid map 2\n");
	if (game->map.map[i - 1][j] != '1' && game->map.map[i - 1][j] != '0' &&
		game->map.map[i - 1][j] != '2')
		ft_mistake("Error: invalid map 3\n");
	if (game->map.map[i][j - 1] != '1' && game->map.map[i][j - 1] != '0' &&
		game->map.map[i][j - 1] != '2')
		ft_mistake("Error: invalid map 4\n");
	if (game->map.map[i + 1][j] != '1' && game->map.map[i + 1][j] != '0' &&
		game->map.map[i + 1][j] != '2')
		ft_mistake("Error: invalid map 5\n");
	if (game->map.map[i][j + 1] != '1' && game->map.map[i][j + 1] != '0' &&
		game->map.map[i][j + 1] != '2')
		ft_mistake("Error: invalid map 6\n");
}

static void	check_map_down(t_game *game)
{
	int	j;

	j = 0;
	while (game->map.map[game->map.height - 1][j])
	{
		if (game->map.map[game->map.height - 1][j] != '1'
            && game->map.map[game->map.height - 1][j] != ' ')
            ft_mistake("map last line\n");
		j++;
	}
}

void	ft_check_close_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	check_map_down(game);
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '0')
				check_position(game, i, j);
			j++;
		}
		i++;
	}
}