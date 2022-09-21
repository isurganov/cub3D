/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:23:20 by ilya              #+#    #+#             */
/*   Updated: 2022/09/21 13:50:15 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	torgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	rgb(char *line)
{
	int		i;
	char	**colors;
	int		rgb;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	colors = ft_split(line, ',');
	if (!colors)
		ft_mistake("Malloc fail in rgb\n");
    printf("%s\n", colors[0]);
	rgb = torgb(ft_atoi(colors[0]),
        ft_atoi(colors[1]),
        ft_atoi(colors[2]));
	free_map(colors);
	return (rgb);
}

static void	check_commas_format(const char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
		if (line[i++] == ',')
			comma++;
	if (comma != 2)
		ft_mistake("Wrong color\n");
}

void    ft_pars_floor_ceiling(char *line, t_game *game)
{
    if ((ft_strncmp(line, "F ", 2) == 0) && game->map.floor == -1)
	{
		check_commas_format(line);
		game->map.floor = rgb(line);
	}
    else if ((ft_strncmp(line, "C ", 2) == 0) && game->map.ceiling == -1)
	{
		check_commas_format(line);
		game->map.ceiling = rgb(line);
	}
    else
        ft_mistake("Color not found\n");
}