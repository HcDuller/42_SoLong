/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 23:22:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 21:53:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	get_exit_from_entities(t_game_handler *game)
{
	t_entity	**ents;

	ents = game->entities;
	game->exit = NULL;
	while (*ents)
	{
		if ((*ents)->type == '4')
			game->exit = new_entity((*ents)->x, (*ents)->y, '4');
		ents++;
	}
}
