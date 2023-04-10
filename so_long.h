/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:52:43 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/10 19:23:34 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		fd;
	int		weight;
	int		height;
	char	**map;
	char	wall;
}			t_list;

int			ft_strstr(char *big, char *little);
int			main(int argc, char **argv);
int 		check_firts_rc(t_list *game);
int 		check_last_rc(t_list *game);

void		init_map(t_list *game, int argc, char **argv);
void		error_msg(char *msg);
void		free_argt(char **argument);
void		check_map(t_list *game);
void		get_height_weight(char **map, t_list *game);

#endif