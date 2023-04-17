/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:34:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/17 18:23:24 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_loop(game->mlx);
}
