/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_overlay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 03:41:47 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	overlay_player(t_game_handler *game)
{
	int			x;
	int			y;
	t_mlx_img	*p;

	x = game->player->x * game->a_size;
	y = game->player->y * game->a_size;
	p = img_from_entity(game, game->player);
	overlay_images(game->mlx.img, p, x, y);
}

void	make_overlay(t_game_handler *game)
{
	int			array_i;
	int			x;
	int			y;
	t_mlx_img	*p;

	override_images(game->mlx.img, game->base_image, 0, 0);
	array_i = 0;
	while ((game->entities)[array_i])
	{
		if (game->entities[array_i]->type != '0' && \
			game->entities[array_i]->active != '1')
		{
			x = game->entities[array_i]->x * game->a_size;
			y = game->entities[array_i]->y * game->a_size;
			p = img_from_entity(game, game->entities[array_i]);
			overlay_images(game->mlx.img, p, x, y);
		}
		array_i++;
	}
	overlay_player(game);
}
