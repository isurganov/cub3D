/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:55:34 by ilya              #+#    #+#             */
/*   Updated: 2022/09/26 13:22:15 by pleoma           ###   ########.fr       */
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
	char	*line_without_n;

	h = -1;
	line_without_n = del_n(line);
	game->map.height++;
	game->map.map_copy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.map_copy)
		ft_mistake("Malloc fail in ft_pars_map\n");
	while (++h < (game->map.height - 1))
		game->map.map_copy[h] = ft_strdup(game->map.map[h]);
	if (check_line_symbols(line_without_n, i))
		game->map.map_copy[h] = ft_strdup(line_without_n);
	else
	{
		free_map(game->map.map_copy);
		ft_mistake("Invalid map in ft_pars_map\n");
	}
	if (game->map.height > 1)
		free_map(game->map.map);
	game->map.map = game->map.map_copy;
	free(line_without_n);
	printf("map[%2.i] = %s\n", h, game->map.map[h]);
}
