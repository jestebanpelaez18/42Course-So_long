/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/02 18:12:43 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(int argc, char *argument)
{
	if (!ft_strstr(argument[1], ".ber"))
		return (0);
	return (1);
}

static char	**read_map(t_list *game, char *file)
{
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		error_msg("Error fd");
	
    
}

void	init_map(t_list *game, int argc, char **argv)
{
	if (!check_file(argc, argv[1]))
		error_msg("Error, invalid file format");
	game->map = read_map(game, argv[1]);
}
