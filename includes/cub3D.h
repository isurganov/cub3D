/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:46:08 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/05 09:36:26 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define BLUE   "\033[0;34m"
# define YELW   "\033[1;33m"
# define WTH    "\033[0;37m"

# define BAD_ARGS "Use: ./cub3d MAP_NAME.cub\n"
# define BAD_EXTS "Extension must be .cub\n"
# define BAD_FILE "Cannot open the map\n"

//  fts_errors.c //
int     ft_mistake(char *arg);

//  check_arg.c //
int    ft_wrong_argument(int argc, char *argv);

//  cub_3D.c //
void    ft_cub3D(const char *map, int fd);

#endif