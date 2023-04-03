/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:55 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/03 18:16:43 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(int argc, char **argument)
{
	if (!ft_strstr(argument[1], ".ber"))
		return (0);
	return (1);
}
// void	printList(t_list *node)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (node->map[i] != NULL)
// 	{
// 		j = 0;
// 		while (node->map[i][j] != '\0')
// 		{
// 			printf("%c", node->map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

// void	printList_2(char **node)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (node[i] != NULL)
// 	{
// 		j = 0;
// 		while (node[i][j] != '\0')
// 		{
// 			printf("%c", node[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

static char	**read_map(t_list *game, char *file)
{
	char	*line;
	char	*full_map;
	char	**final_map;

	line = ft_strdup("");
	full_map = ft_strdup("");
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		error_msg("Error fd");
	while (1)
	{
		line = get_next_line(game->fd);
		if (line == NULL || line[0] == '\n')
			break ;
		full_map = ft_strjoin(full_map, line);
	}
	close(game->fd);
	final_map = ft_split(full_map, '\n');
	// printList_2(final_map);
	// printf("\n\n");
	free(line);
	free(full_map);
	return (final_map);
}

void	init_map(t_list *game, int argc, char **argv)
{
	if (!check_file(argc, argv))
		error_msg("Error, invalid file format");
	game->map = read_map(game, argv[1]);
	// printList(game);
}
