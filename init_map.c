/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/04 13:05:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(int argc, char **argument)
{
	if (!ft_strstr(argument[1], ".ber"))
		return (0);
	return (1);
}

static char	**read_map(t_list *game, char *file)
{
	char	*line;
	char	*full_map;
	char	**final_map;

	line = "";
	full_map = ft_strdup("");
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		error_msg("Error fd");
	while (1)
	{
		line = get_next_line(game->fd);
		if (line == NULL || line[0] == '\n')
			break ;
		full_map = ft_strjoin2(full_map, line);
		free(line);
	}
	free(line);
	close(game->fd);
	final_map = ft_split(full_map, '\n');
	if (!final_map[0])
		free_argt_exit(final_map);
	free(full_map);
	return (final_map);
}

static int	n_rows(t_list *game, char *file)
{
	int		rows;
	char	*line;

	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		error_msg("Error fd");
	rows = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(game->fd);
	}
	close(game->fd);
	return (rows);
}

void	init_map(t_list *game, int argc, char **argv)
{
	if (!check_file(argc, argv))
		error_msg("Error, invalid file format");
	game->map = read_map(game, argv[1]);
	game->temp_map = read_map(game, argv[1]);
	game->n_rows = n_rows(game, argv[1]);
}
