/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:23:08 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/24 17:37:05 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_argt(char **argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		free(argument[i]);
		argument[i] = NULL;
		i++;
	}
	free(argument);
}

void	exit_game(t_list *game)
{
	free_argt(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}