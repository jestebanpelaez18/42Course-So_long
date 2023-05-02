/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:51:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/02 15:37:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_position(t_list *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->s_x = i;
				game->s_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

char	**copy_map(char **node, int row, int col)
{
	char	**s2;
	int		i;
	int		j;

	s2 = malloc(sizeof(char *) * (row + 1));
	i = 0;
	while (node[i] != NULL)
	{
		s2[i] = malloc(sizeof(char) * (col));
		j = 0;
		while (node[i][j] != '\0')
		{
			s2[i][j] = node[i][j];
			j++;
		}
		s2[i][j] = '\0';
		i++;
	}
	return (s2);
}
