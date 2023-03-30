/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/03/30 17:22:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(int argc, char *argument)
{
	if (argc < 2)
		return (0);
	if (!ft_strstr(argument[1], ".ber"))
		return (0);
	return (1);
}

static int	read_map(t_list *game, char *file)
{
	game->fd = open(file[1], O_RDONLY);
	if (game->fd == -1)
		return (0);
    
}

int	init_map(t_list *game, int argc, char **argv)
{
	char	**map;

	if (!check_file(argc, argv[1]))
		return (0);
	if (!read_map(game, argv[1]))
		return (0);
}
