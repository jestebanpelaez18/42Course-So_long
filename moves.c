/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:02 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/25 13:17:42 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void right(t_list *game, , int y, int x)
{
    
}

void left(t_list *game, int y, int x)
{
    
}

void up(t_list *game, int y, int x)
{
    
}

void down(t_list *game, int y, int x)
{
    if(game->map[y+1][x] == 'E')
    {
        if(game->n_collect == 0)
            exit_game(game);
    }
    if(game->map[y+1][x] != '1')
    {
        game->p_y += 1;
         
    }

}