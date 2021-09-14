/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:21:49 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 19:36:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	*load_player(t_mlx_handler *mlx)
{
	t_sprite	*sprt;

	sprt = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	sprt->type = '3';
	sprt->n_sprites = 4;
	sprt->sprite = ft_calloc(sprt->n_sprites + 1, sizeof(t_mlx_img *));
	sprt->sprite[0] = img_from_file_2(mlx->conn, "./assets/player/idle_01.xpm");
	sprt->sprite[1] = img_from_file_2(mlx->conn, "./assets/player/idle_02.xpm");
	sprt->sprite[2] = img_from_file_2(mlx->conn, "./assets/player/bark_01.xpm");
	sprt->sprite[3] = img_from_file_2(mlx->conn, "./assets/player/bark_02.xpm");
	sprt->sprite[4] = NULL;
	return (sprt);
}
