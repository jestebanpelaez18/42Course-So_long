/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/04 13:33:24 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_text(t_list *game)
{
	char	*n_moves;
	char	*string;

	n_moves = ft_itoa(game->moves);
	string = ft_strjoin("Nºmoves: ", n_moves);
	mlx_put_image_to_window(game->mlx, game->win, game->water, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->water, 64, 0);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x008000, string);
	ft_putendl_fd(string, 1);
	free(string);
	free(n_moves);
}

void	right(t_list *game, int y, int x)
{
	if (game->map[y / 64][(x / 64) + 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	if (game->map[y / 64][(x / 64) + 1] != '1')
	{
		if (game->map[y / 64][(x / 64)] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
		game->p_x += 64;
		if (game->map[y / 64][(x / 64) + 1] == 'C')
		{
			game->n_collect--;
			game->map[y / 64][(x / 64) + 1] = '0';
		}
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->p_x,
			game->p_y);
		put_text(game);
	}
}

void	left(t_list *game, int y, int x)
{
	if (game->map[y / 64][(x / 64) - 1] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	if (game->map[y / 64][(x / 64) - 1] != '1')
	{
		if (game->map[y / 64][(x / 64)] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
		game->p_x -= 64;
		if (game->map[y / 64][(x / 64) - 1] == 'C')
		{
			game->n_collect--;
			game->map[y / 64][(x / 64) - 1] = '0';
		}
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->p_x,
			game->p_y);
		put_text(game);
	}
}

void	up(t_list *game, int y, int x)
{
	if (game->map[(y / 64) - 1][x / 64] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	if (game->map[(y / 64) - 1][x / 64] != '1')
	{
		if (game->map[y / 64][(x / 64)] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
		game->p_y -= 64;
		if (game->map[(y / 64) - 1][x / 64] == 'C')
		{
			game->n_collect--;
			game->map[(y / 64) - 1][x / 64] = '0';
		}
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->p_x,
			game->p_y);
		put_text(game);
	}
}

void	down(t_list *game, int y, int x)
{
	if (game->map[(y / 64) + 1][x / 64] == 'E')
	{
		if (game->n_collect == 0)
			exit_game(game);
	}
	if (game->map[(y / 64) + 1][x / 64] != '1')
	{
		if (game->map[y / 64][(x / 64)] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->grass, x, y);
		game->p_y += 64;
		if (game->map[(y / 64) + 1][x / 64] == 'C')
		{
			game->n_collect--;
			game->map[(y / 64) + 1][x / 64] = '0';
		}
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->p_x,
			game->p_y);
		put_text(game);
	}
}
