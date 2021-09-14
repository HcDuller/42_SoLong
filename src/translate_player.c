/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:58:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	int	has_collectables(t_game_handler *game)
{
	int	i;

	i = 0;
	while (game->entities[i])
	{
		if (game->entities[i]->type == '2')
			return (1);
		i++;
	}
	return (0);
}

void	translate_player(t_game_handler *game, int d_x, int d_y)
{	
	t_entity	*nxt_ent;
	t_entity	*player;

	player = game->player;
	game->moves++;
	nxt_ent = get_ent_by_pos(game->entities, player->x + d_x, player->y + d_y);
	if (nxt_ent->type == '2')
		nxt_ent->type = '0';
	if (nxt_ent->type == '4')
	{
		if (!has_collectables(game))
		{
			ft_putstr_fd("Parabens, voce venceu.\n", 1);
			game->won = 1;
		}
	}
	player->x += d_x;
	player->y += d_y;
}
