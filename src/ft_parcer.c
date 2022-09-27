/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:40 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/26 13:20:17 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	single_line_parsing(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strchr("NSWE", line[i]))
		ft_pars_walls(line + i, game);
	if (ft_strchr("FC", line[i]))
		ft_pars_floor_ceiling(line + i, game);
	if (ft_strchr("01", line[i]))
		ft_pars_map(line, i, game);
	free(line);
}

void	ft_parcer(t_game *game, int file_descriptor)
{
	char	*line;

	line = get_next_line(file_descriptor);
	while (line)
	{
		single_line_parsing(line, game);
		line = get_next_line(file_descriptor);
		if (line == NULL)
			break ;
	}
	free(line);
	ft_checker(game);
	close (file_descriptor);
}
