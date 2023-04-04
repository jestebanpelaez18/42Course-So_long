/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:53:11 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/04 16:49:34 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	game;

	if (argc < 2)
		error_msg("Error, number of arguments invalid");
	init_map(&game, argc, argv);
	check_map(&game);
	return (0);
}
