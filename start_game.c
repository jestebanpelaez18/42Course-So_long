/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:34:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/27 13:36:23 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	image_components(t_list *game, char map_com, int x, int y)
{
	if (map_com == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->water, y, x);
	if (map_com == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, y, x);
	if (map_com == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, y, x);
	if (map_com == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, y, x);
		mlx_put_image_to_window(game->mlx, game->win, game->collect, y, x);
	}
	if (map_com == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, y, x);
		mlx_put_image_to_window(game->mlx, game->win, game->player, y, x);
		game->p_x = y;
		game->p_y = x;
	}
}

static void	put_image(t_list *game)
{
	int	x_axis;
	int	y_axis;
	int	i;
	int	j;

	x_axis = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		y_axis = 0;
		j = 0;
		while (game->map[i][j] != '\0')
		{
			image_components(game, game->map[i][j], x_axis, y_axis);
			y_axis += 64;
			j++;
		}
		x_axis += 64;
		i++;
	}
}

static void	set_image(t_list *game)
{
	int	img_width;
	int	img_height;

	game->collect = mlx_xpm_file_to_image(game->mlx, "img/master64.xpm",
			&img_width, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/player64.xpm",
			&img_width, &img_height);
	game->water = mlx_xpm_file_to_image(game->mlx, "img/wwater64.xpm",
			&img_width, &img_height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "img/freegrass64.xpm",
			&img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/hueco64.xpm", &img_width,
			&img_height);
}

static int	keys(int key_code, t_list *game)
{
	if ((key_code == 2) || (key_code == 124))
		right(game, game->p_y, game->p_x);
	else if ((key_code == 0) || (key_code == 123))
		left(game, game->p_y, game->p_x);
	else if ((key_code == 1) || (key_code == 125))
		down(game, game->p_y, game->p_x);
	else if ((key_code == 13) || (key_code == 126))
		up(game, game->p_y, game->p_x);
	else if (key_code == 53)
	{
		free_argt(game->map);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

void	start_game(t_list *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->weight) * 64, (game->height)
			* 64, "So Long Juanes");
	set_image(game);
	put_image(game);
	mlx_hook(game->win, 2, 1L << 0, keys, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
