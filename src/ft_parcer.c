/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:40 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/19 14:23:22 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	single_line_parsing(char *line, t_game *game)
{
	(void) game;
	
	free(line);
}

void    ft_parcer(t_game *game, int file_descriptor)
{
    char	*line;

	(void) game;
	line = get_next_line(file_descriptor);
	while (line != NULL)
	{
		single_line_parsing(line, game);
		line = get_next_line(file_descriptor);
		if (line == NULL)
			break ;
	}
    free(line);
	//ft_checker();
    close (file_descriptor);
}
