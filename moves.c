/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/26 17:44:08 by jpelaez-         ###   ########.fr       */
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
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, x + 64, y);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 64, 0);
		mlx_string_put(game->mlx, game->win, 0, 0, 0x008000,
			ft_strjoin("Nºmoves: ", ft_itoa(game->moves)));
		ft_putendl_fd(ft_strjoin("Nºmoves: ", ft_itoa(game->moves)), 1);
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
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, x - 64, y);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 64, 0);
		mlx_string_put(game->mlx, game->win, 0, 0, 0x008000,
			ft_strjoin("Nºmoves: ", ft_itoa(game->moves)));
		ft_putendl_fd(ft_strjoin("Nºmoves: ", ft_itoa(game->moves)), 1);
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
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y - 64);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 64, 0);
		mlx_string_put(game->mlx, game->win, 0, 0, 0x008000,
			ft_strjoin("Nºmoves: ", ft_itoa(game->moves)));
		ft_putendl_fd(ft_strjoin("Nºmoves: ", ft_itoa(game->moves)), 1);
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
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y + 64);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->water, 64, 0);
		mlx_string_put(game->mlx, game->win, 0, 0, 0x008000,
			ft_strjoin("Nºmoves: ", ft_itoa(game->moves)));
		ft_putendl_fd(ft_strjoin("Nºmoves: ", ft_itoa(game->moves)), 1);
	}
}
