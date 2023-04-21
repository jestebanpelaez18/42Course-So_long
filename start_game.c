/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:34:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/21 17:42:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->water,
					x_axis, y_axis);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->grass,
					x_axis, y_axis);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit,
					x_axis, y_axis);
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->grass,
					x_axis, y_axis);
				mlx_put_image_to_window(game->mlx, game->win, game->collect,
					x_axis, y_axis);
			}
			if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->grass,
					x_axis, y_axis);
				mlx_put_image_to_window(game->mlx, game->win, game->player,
					x_axis, y_axis);
			}
			y_axis += 120;
			j++;
		}
		x_axis += 120;
		i++;
	}
}

static void	set_image(t_list *game)
{
	int	img_width;
	int	img_height;

	game->collect = mlx_xpm_file_to_image(game->mlx, "img/master.xpm",
			&img_width, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/2player.xpm",
			&img_width, &img_height);
	game->water = mlx_xpm_file_to_image(game->mlx, "img/wwall.xpm", &img_width,
			&img_height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "img/freegrass.xpm",
			&img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/hueco.xpm",
			&img_width, &img_height);
}
static int keys(int key_code, t_list *game)
{
	
}
void	start_game(t_list *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->height) * 120, (game->weight)
			* 120, "So Long Juanes");
	set_image(game);
	put_image(game);
	mlx_hook(game->win, 2 , 1L<<0, keys, game);
	mlx_loop(game->mlx);
}
