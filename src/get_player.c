/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 23:22:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 21:52:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	get_player(t_game_handler *game)
{
	t_entity	**ents;
	t_entity	*player;

	ents = game->entities;
	game->player = NULL;
	while (*ents)
	{
		if ((*ents)->type == '3')
		{
			player = *ents;
			player->type = '0';
			game->player = new_entity((*ents)->x, (*ents)->y, '3');
		}
		ents++;
	}
}
