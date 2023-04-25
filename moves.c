/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/25 14:17:32 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_collect(t_list *game)
{
	game->n_collect -= 1;
	if (game->n_collect == 0)
		exit_game(game);
}

void	right(t_list *game, int y, int x)
{
	if (game->map[y][x - 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[y][x - 1] != '1')
	{
		game->p_x -= 1;
		if (game->map[y][x - 1] == 'C')
			check_collect(game);
	}
}

void	left(t_list *game, int y, int x)
{
	if (game->map[y][x + 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[y][x + 1] != '1')
	{
		game->p_x += 1;
		if (game->map[y][x + 1] == 'C')
			check_collect(game);
	}
}

void	up(t_list *game, int y, int x)
{
	if (game->map[y - 1][x] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[y - 1][x] != '1')
	{
		game->p_y -= 1;
		if (game->map[y - 1][x] == 'C')
			check_collect(game);
	}
}

void	down(t_list *game, int y, int x)
{
	if (game->map[y + 1][x] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[y + 1][x] != '1')
	{
		game->p_y += 1;
		if (game->map[y + 1][x] == 'C')
			check_collect(game);
	}
}
