/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:58:27 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/04 20:11:55 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_entity	*new_entity(int x, int y, char type)
{
	t_entity	*entity;

	entity = ft_calloc(1, sizeof(t_entity));
	entity->active = 1;
	entity->x = x;
	entity->y = y;
	entity->type = type;
	entity->spr_i = 0;
	return (entity);
}
