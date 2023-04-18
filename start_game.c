/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:34:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/18 15:47:58 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_list *game)
{
	int	x_axis;
	int	y_axis;

	x_axis = 0;
	while (game->map[x_axis] != NULL)
	{
		y_axis = 0;
		while (game->map[x_axis][y_axis] != '\0')
		{
			if (game->map[x_axis][y_axis] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect,
					x_axis, y_axis);
			y_axis++;
		}
		x_axis++;
	}
}

static void	set_image(t_list *game)
{
	int	img_width;
	int	img_height;

	game->collect = mlx_xpm_file_to_image(game->mlx, "img/collect.xpm",
			&img_width, &img_height);
}

void	start_game(t_list *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->height) * 150, (game->weight)
			* 100, "So Long Juanes");
	set_image(game);
	put_image(game);
	mlx_loop(game->mlx);
}
