/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/26 16:39:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_list *game, int y, int x)
{
	if (game->map[(y / 64)][(x / 64) + 1] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[y / 64][(x / 64) + 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
	}
	else if (game->map[y / 64][(x / 64) + 1] != '1')
	{
		game->p_x += 64;
		if (game->map[y / 64][(x / 64) + 1] == 'C')
		{
			game->n_collect--;
			game->map[y / 64][(x / 64) + 1] = '0';
		}
		mlx_put_image_to_window(game->mlx, game->win, game->player, x + 64, y);
	}
}

void	left(t_list *game, int y, int x)
{
	if (game->map[(y / 64)][(x / 64) - 1] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[y / 64][(x / 64) - 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
	}
	else if (game->map[y / 64][(x / 64) - 1] != '1')
	{
		game->p_x -= 64;
		if (game->map[y / 64][(x / 64) - 1] == 'C')
		{
			game->n_collect--;
			game->map[y / 64][(x / 64) - 1] = '0';
		}
		mlx_put_image_to_window(game->mlx, game->win, game->player, x - 64, y);
	}
}

void	up(t_list *game, int y, int x)
{
	if (game->map[(y / 64) - 1][x / 64] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[(y / 64) - 1][x / 64] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
	}
	else if (game->map[(y / 64) - 1][x / 64] != '1')
	{
		game->p_y -= 64;
		if (game->map[(y / 64) - 1][x / 64] == 'C')
		{
			game->n_collect--;
			game->map[(y / 64) - 1][x / 64] = '0';
		}
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y - 64);
	}
}

void	down(t_list *game, int y, int x)
{
	if (game->map[(y / 64) + 1][x / 64] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
	if (game->map[(y / 64) + 1][x / 64] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
	}
	else if (game->map[(y / 64) + 1][x / 64] != '1')
	{
		game->p_y += 64;
		if (game->map[(y / 64) + 1][x / 64] == 'C')
		{
			game->n_collect--;
			game->map[(y / 64) + 1][x / 64] = '0';
		}
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y + 64);
	}
}
