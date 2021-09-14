/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 01:26:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	can_move_to(t_game_handler *game, int x, int y)
{
	t_entity	*ent;

	if (x >= game->x_max || y >= game->y_max)
		return (0);
	ent = get_ent_by_pos(game->entities, x, y);
	if (ent == NULL)
		return (0);
	if (ent->type == '1')
		return (0);
	return (1);
}
