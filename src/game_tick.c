/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 15:03:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	overlay_moves(t_game_handler *game)
{
	char	*str;
	char	*moves;

	moves = ft_itoa(game->moves);
	str = ft_strjoin("Movements made: ", moves);
	free(moves);
	mlx_string_put(game->mlx.conn, game->mlx.win, 10, 20, 0x00ff0000, str);
	free(str);
}

int	game_tick(t_game_handler *game)
{
	int	base_ticker;

	base_ticker = 8000;
	game->tick++;
	if (game->tick % base_ticker == 0)
	{
		make_overlay(game);
		mlx_put_image_to_window(game->mlx.conn, game->mlx.win, \
								game->mlx.img->addr, 0, 0);
		overlay_moves(game);
		game->handling_event = 0;
	}
	if (game->tick % (base_ticker * 10) == 0 && game->won)
		close_win(game);
	return (0);
}
