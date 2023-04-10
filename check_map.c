/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:53:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/10 19:33:04 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_rectangular(t_list *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
			j++;
		if (j != game->weight)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_list *game)
{
	if(!check_firts_rc(game))
		return(0);
	if(!check_last_rc(game))
		return (0);
	return(1);
}
void	check_map(t_list *game)
{
	if (game->map == NULL)
		error_msg("Error, empty map");
	get_height_weight(game->map, game);
	if (!map_rectangular(game))
		error_msg("Error,the map is not rectangular");
	if(!check_walls(game))
		error_msg("Error, the map is not surrounded by walls");
}
