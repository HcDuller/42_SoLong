/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:21:22 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 20:44:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	close_win(t_game_handler *game)
{
	mlx_clear_window(game->mlx.conn, game->mlx.win);
	destroy_entity(game->player);
	destroy_entity(game->exit);
	destroy_entities(game->entities);
	destroy_game_sprites(&game->mlx, game->sprites);
	destroy_t_mlx_img(&game->mlx, game->mlx.img);
	destroy_t_mlx_img(&game->mlx, game->base_image);
	mlx_destroy_window(game->mlx.conn, game->mlx.win);
	mlx_destroy_display(game->mlx.conn);
	free(game->mlx.conn);
	exit(0);
}
