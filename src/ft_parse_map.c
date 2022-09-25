/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:55:34 by ilya              #+#    #+#             */
/*   Updated: 2022/09/23 09:09:32 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static bool	check_line_symbols(char *line, int i)
{
	while (line[i])
        if (!ft_strchr("10NSEW \t", line[i++]))
            return (false);
	return (true);
}

void	ft_pars_map(char *line, int i, t_game *game)
{
    int		h;

	h = -1;
    line = del_n(line);
	game->map.height++;
	game->map.map_copy = (char **) ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.map_copy)
		ft_mistake("Malloc fail in ft_pars_map\n");
	while (++h < (game->map.height - 1))
		game->map.map_copy[h] = ft_strdup(game->map.map[h]);
	if (check_line_symbols(line, i))
		game->map.map_copy[h] = ft_strdup(line);
	else
	{
		free_map(game->map.map_copy);
		ft_mistake("Invalid map in ft_pars_map\n");
	}
	if (game->map.height > 1)
		free_map(game->map.map);
	game->map.map = game->map.map_copy;
	printf("map[%2.i] = %s\n", h, game->map.map[h]);
}