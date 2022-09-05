/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:39:37 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/05 09:30:47 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*  Checks number of arguments and
    the extension of map, requires
    string.h for strcmp         */

int    ft_wrong_argument(int argc, char *argv)
{
    char	*ext;
    
    if (argc != 2)
        return(ft_mistake(BAD_ARGS));
    ext = ft_strrchr(argv, '.');
	if (!ext || ft_strcmp(ext, ".cub"))
		return (ft_mistake(BAD_EXTS));
    return (EXIT_SUCCESS);
}