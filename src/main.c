/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:22:17 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/18 16:25:39 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void    ft_check_argument(int argc, char *argv)
{
    char	*ext;
    
    if (argc != 2)
        ft_mistake(BAD_ARGS);
    ext = ft_strrchr(argv, '.');
	if (!ext || ft_strcmp(ext, ".cub"))
		ft_mistake(BAD_EXTS);
}

int main(int argc, char **argv)
{
	t_game game;

	ft_check_argument(argc, argv[1]);
	ft_cub3D(&game, argv);
    return (EXIT_SUCCESS);
}