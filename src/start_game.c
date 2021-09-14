/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 03:08:13 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:58:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_game(t_game_handler *game, t_lines *map)
{
	game->mlx.conn = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.conn, map->l_len * 64, \
									map->size * 64, "Title");
	game->entities = fill_entities(*map);
	game->sprites = load_sprites(&(*game).mlx);
	game->moves = 0;
	game->tick = 0;
	game->won = 0;
	game->a_size = game->sprites[0]->sprite[0]->height;
	game->x_max = map->l_len - 1;
	game->y_max = map->size - 1;
	game->handling_event = 0;
	game->moves = 0;
	game->mlx.img = new_blank_image(game->mlx.conn, \
	(game->x_max + 1) * game->a_size, (game->y_max + 1) * game->a_size);
	get_player(game);
	get_exit_from_entities(game);
	make_base_map(game);
	make_overlay(game);
}
