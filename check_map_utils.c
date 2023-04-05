/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:27:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/05 17:13:46 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_height_weight(char **map, t_list *game)
{
	int	i;
	int	w_counter;
	int	j;

	i = 0;
	w_counter = 1;
	j = 0;
	while (map[j][i] != '\0')
	{
		game->weight = w_counter;
		w_counter++;
		i++;
	}
	// while (map[j][i] != NULL)
	// 	game->height = j++;
}
