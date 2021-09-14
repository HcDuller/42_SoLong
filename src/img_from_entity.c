/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_from_entity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:37:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 03:41:17 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_mlx_img	*img_from_entity(t_game_handler *game, t_entity *ent)
{
	int			i;
	t_sprite	**spr;

	i = 0;
	spr = game->sprites;
	while (spr[i])
	{
		if (spr[i]->type == ent->type)
		{
			ent->spr_i = (ent->spr_i + 1) % spr[i]->n_sprites;
			return (spr[i]->sprite[ent->spr_i]);
		}
		i++;
	}
	return (spr[0]->sprite[0]);
}
