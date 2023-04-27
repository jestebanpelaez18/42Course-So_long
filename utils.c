/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:40:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/27 14:09:41 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strstr(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return (0);
	while (*big != '\0')
	{
		if (*little == *big)
		{
			j = 1;
			while (little[j] == big[j] && little[j] != '\0')
			{
				j++;
			}
			if (little[j] == '\0')
				return (1);
		}
		big++;
		i++;
	}
	return (0);
}
