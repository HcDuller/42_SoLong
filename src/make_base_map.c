/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_base_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 02:43:51 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 03:43:53 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	make_base_map(t_game_handler *game)
{
	int			array_i;
	int			x;
	int			y;
	t_mlx_img	*p;

	game->base_image = new_blank_image(game->mlx.conn, (game->x_max + 1) * \
							game->a_size, (game->y_max + 1) * game->a_size);
	array_i = 0;
	while ((game->entities)[array_i])
	{
		x = game->entities[array_i]->x * game->a_size;
		y = game->entities[array_i]->y * game->a_size;
		if (game->entities[array_i]->type != '1')
			p = get_image_by_type(game, '0');
		else
			p = get_image_by_type(game, '1');
		overlay_images(game->base_image, p, x, y);
		array_i++;
	}
}
