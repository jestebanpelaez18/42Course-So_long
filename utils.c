/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:40:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/27 15:23:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strstr(char *big, char *little)
{
	size_t	j;

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
				break ;
		}
		big++;
	}
	if (little[j] == '\0' && big[j] == '\0')
		return (1);
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}
