/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:06:04 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/26 13:19:49 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static char	*addr_to_path(t_game *game, char *path, int index)
{
	int		i;
	int		x;
	int		y;
	char	*img_adr;

	game->img.img_t[index] = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	if (game->img.img_t[index] == NULL
		|| x != T_WIDTH
		|| y != T_HEIGHT)
		ft_mistake(BAD_XPM);
	img_adr = mlx_get_data_addr(game->img.img_t[index], &x, &y, &i);
	free(path);
	return (img_adr);
}

char	*del_n(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc (sizeof(char) * ft_strlen(line));
	if (!tmp)
		ft_mistake("del_n malloc\n");
	while (line[i] != '\n' && line[i] != '\0')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*get_addr(t_game *game, char *line, int index)
{
	char	*line_without_n;

	line_without_n = NULL;
	line_without_n = line;
	if (line[0] == '.' && line[1] == '/')
	{
		line_without_n = del_n(line);
		return (addr_to_path(game, line_without_n, index));
	}
	else
	{
		ft_mistake(BAD_SPR);
		return (NULL);
	}	
}

void	ft_pars_walls(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && game->map.north_sprite == NULL)
		game->map.north_sprite = get_addr(game, line + 3, NO);
	else if (ft_strncmp(line, "SO ", 3) == 0 && game->map.south_sprite == NULL)
		game->map.south_sprite = get_addr(game, line + 3, SO);
	else if (ft_strncmp(line, "WE ", 3) == 0 && game->map.west_sprite == NULL)
		game->map.west_sprite = get_addr(game, line + 3, WE);
	else if (ft_strncmp(line, "EA ", 3) == 0 && game->map.east_sprite == NULL)
		game->map.east_sprite = get_addr(game, line + 3, EA);
	else
		ft_mistake(BAD_SPR_NAME);
}
