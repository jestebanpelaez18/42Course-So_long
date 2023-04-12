/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:27:19 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/12 15:14:56 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_height_weight(char **map, t_list *game)
{
	int	i;
	int	w_counter;
	int	h_counter;
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
	h_counter = 1;
	while (map[j] != NULL)
	{
		game->height = h_counter;
		h_counter++;
		j++;
	}
}

int	check_firts_rc(t_list *game)
{
	int	i;

	i = 0;
	while (i < game->weight)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_last_rc(t_list *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][game->weight - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->weight)
	{
		if (game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	scan_n_char(t_list *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->n_exit++;
			if (game->map[i][j] == 'P')
				game->n_start++;
			if (game->map[i][j] == 'C')
				game->n_collect++;
			j++;
		}
		i++;
	}
}

int	check_wrong_input(t_list *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == '1'
				|| game->map[i][j] == '0' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
