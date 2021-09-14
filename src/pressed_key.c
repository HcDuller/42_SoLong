/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressed_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:47:33 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:53:34 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	int	*pos_array(t_entity *player, int x, int y)
{
	int	*pos;

	pos = (int *)ft_calloc(4, sizeof(int));
	pos[0] = player->x;
	pos[1] = player->y;
	pos[2] = player->x + x;
	pos[3] = player->y + y;
	return (pos);
}

static	int	allowed_key(int key)
{
	if (key == 0xff1b || key == 0x0077 || \
	key == 0x0061 || key == 0x0073 || key == 0x0064)
		return (1);
	return (0);
}

static	int	*make_positions(t_game_handler *game, int key_code)
{
	int			*p;
	t_entity	*player;

	player = game->player;
	if (key_code == 0x0077)
		p = pos_array(player, 0, -1);
	if (key_code == 0x0061)
		p = pos_array(player, -1, 0);
	if (key_code == 0x0073)
		p = pos_array(player, 0, 1);
	if (key_code == 0x0064)
		p = pos_array(player, 1, 0);
	return (p);
}

int	pressed_key(int key_code, t_game_handler *game)
{
	int			*p;

	if (!allowed_key(key_code))
		return (0);
	if (key_code == 0xff1b)
		close_win(game);
	if (game->handling_event == 0)
	{
		game->handling_event = 1;
		p = make_positions(game, key_code);
		if (can_move_to(game, p[2], p[3]))
			translate_player(game, p[2] - p[0], p[3] - p[1]);
		free(p);
	}
	return (0);
}
