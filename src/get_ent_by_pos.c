/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ent_by_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/04 18:11:23 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_entity	*get_ent_by_pos(t_entity **entities, int x, int y)
{
	int	i;

	i = 0;
	while (entities[i])
	{
		if (entities[i]->active)
		{
			if (entities[i]->x == x && entities[i]->y == y)
				return (entities[i]);
		}
		i++;
	}
	return (NULL);
}
