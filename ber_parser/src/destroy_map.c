/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:00:27 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:09:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

void	destroy_map(t_lines *map)
{
	int	i;

	i = 0;
	while (map->lines[i])
	{
		free(map->lines[i]);
		map->lines[i] = NULL;
		i++;
	}
	free(map->lines);
	map->lines = NULL;
}
