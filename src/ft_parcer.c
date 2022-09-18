/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:47:40 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/18 16:52:30 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void    ft_parcer(t_game *game, int file_descriptor)
{
    (void) game; //

    char	*line;
    
	line = get_next_line(file_descriptor);
    printf("LINE: %s\n", line);
    printf("FD: %i\n", file_descriptor);

    close (file_descriptor);
}
