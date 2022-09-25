/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:33:01 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/25 17:57:10 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_mistake(char *arg)
{
	fprintf(stderr, RED "Error: " WTH);
	fprintf(stderr, "%s", arg);
	exit (EXIT_FAILURE);
}
