/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:40 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/19 17:07:57 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	single_line_parsing(char *line, t_game *game)
{
	int	i;

	i = 0;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_strncmp("NSWE", line + i, 1))
		ft_pars_walls(line, game);
	//map
	//wals
	//fc
	//playaer
	free(line);
}

void    ft_parcer(t_game *game, int file_descriptor)
{
    char	*line;

	line = get_next_line(file_descriptor);
	
	while (line)
	{
		printf("%s", line);
		single_line_parsing(line, game);
		line = get_next_line(file_descriptor);
		if (line == NULL)
			break ;
	}
    free(line);
	//ft_checker();
    close (file_descriptor);
}
