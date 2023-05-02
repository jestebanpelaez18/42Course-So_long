/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:52:43 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/02 15:22:58 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		fd;
	int		weight;
	int		height;
	int		n_exit;
	int		n_start;
	int		n_collect;
	int		s_x;
	int		s_y;
	int		p_x;
	int		p_y;
	int		moves;
	char	**map;
	char	wall;
	void	*mlx;
	void	*win;
	void	*collect;
	void	*water;
	void	*grass;
	void	*exit;
	void	*player;
}			t_list;

int			ft_strstr(char *big, char *little);
int			main(int argc, char **argv);
int			check_firts_rc(t_list *game);
int			check_last_rc(t_list *game);
int			check_wrong_input(t_list *game);
int			close_game(t_list *game);

void		init_map(t_list *game, int argc, char **argv);
void		error_msg(char *msg);
void		free_argt(char **argument);
void		check_map(t_list *game);
void		get_height_weight(t_list *game);
void		scan_n_char(t_list *game);
void		start_position(t_list *game);
void		start_game(t_list *game);
void		exit_game(t_list *game);
void		right(t_list *game, int y, int x);
void		left(t_list *game, int y, int x);
void		down(t_list *game, int y, int x);
void		up(t_list *game, int y, int x);

char		*ft_strjoin2(char *s1, char *s2);
char		**copy_map(char **node, int row, int col);

#endif