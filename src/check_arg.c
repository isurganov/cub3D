/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:39:37 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/04 21:03:54 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int    ft_wrong_argument(int argc, char **argv)
{
    if (argc != 2)
        return(ft_mistake(BAD_ARGS));
    
    (void) argv;
    //.cub
    return (EXIT_SUCCESS);
}