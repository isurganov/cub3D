/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:22:17 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/04 21:06:03 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int argc, char **argv)
{
    int	file_descriptor;
	
	if (ft_wrong_argument(argc, argv))
		return (EXIT_FAILURE);
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor < 0)
		return (ft_mistake(BAD_FILE));
	
    printf("IT WORKS\n");
	
    return (EXIT_SUCCESS);
}