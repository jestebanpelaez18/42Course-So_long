/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/26 15:46:20 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_collect(t_list *game, int y, int x)
{
	game->n_collect--;
	if (game->n_collect == 0)
		exit_game(game);
}

void	right(t_list *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[y / 64][(x / 64) + 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[y / 64][(x / 64) + 1] != '1')
	{
		game->p_x += 64;
		if (game->map[y / 64][(x / 64) + 1] == 'C')
		{
			check_collect(game, y, game->p_x);
			game->map[y / 64][(x / 64) + 1] = '0';
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player, x + 64, y);
}

void	left(t_list *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[y / 64][(x / 64) - 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[y / 64][(x / 64) - 1] != '1')
	{
		game->p_x -= 64;
		if (game->map[y / 64][(x / 64) - 1] == 'C')
		{
			check_collect(game, y, game->p_x);
			game->map[y / 64][(x / 64) - 1] = '0';
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player, x - 64, y);
}

void	up(t_list *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[(y / 64) - 1][x / 64] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[(y / 64) - 1][x / 64] != '1')
	{
		game->p_y -= 64;
		if (game->map[(y / 64) - 1][x / 64] == 'C')
		{
			check_collect(game, game->p_y, x);
			game->map[(y / 64) - 1][x / 64] = '0';
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player, x, y - 64);
}

void	down(t_list *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[(y / 64) + 1][x / 64] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	else if (game->map[(y / 64) + 1][x / 64] != '1')
	{
		game->p_y += 64;
		if (game->map[(y / 64) + 1][x / 64] == 'C')
		{
			check_collect(game, game->p_y, x);
			game->map[(y / 64) + 1][x / 64] = '0';
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player, x, y + 64);
}
