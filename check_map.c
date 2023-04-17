/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:53:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/17 14:25:38 by jpelaez-         ###   ########.fr       */
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
	if (!check_firts_rc(game))
		return (0);
	if (!check_last_rc(game))
		return (0);
	return (1);
}

static void	check_chars(t_list *game)
{
	if (!check_wrong_input(game))
		error_msg("Error, find not valid character");
	scan_n_char(game);
	if (game->n_exit > 1 || game->n_exit == 0)
		error_msg("Error, incorrect number of exits");
	else if (game->n_start > 1 || game->n_start == 0)
		error_msg("Error, incorrect number of starts");
	else if (game->n_collect == 0)
		error_msg("Error, not collectible in the map");
}

// static int	check_path_of_map(t_list *game, int x, int y)
// {
// 	if (game->map[x + 1][y + 1] == '0' && game->map[x - 1][y - 1] == '0')
// 		// check_path_of_map()
// }


void	check_map(t_list *game)
{
	if (game->map == NULL)
		error_msg("Error, empty map");
	get_height_weight(game->map, game);
	if (!map_rectangular(game))
		error_msg("Error,the map is not rectangular");
	if (!check_walls(game))
		error_msg("Error, the map is not surrounded by walls");
	check_chars(game);
	start_position(game);
	// if (!check_path_of_map(game, game->s_x, game->s_y))
	// 	error_msg("Error, not valid path in the map");
}
