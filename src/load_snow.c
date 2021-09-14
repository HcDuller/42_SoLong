/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_snow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:21:29 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 19:37:18 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	*load_snow(t_mlx_handler *mlx)
{
	t_sprite	*sprt;

	sprt = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	sprt->type = '0';
	sprt->n_sprites = 1;
	sprt->sprite = ft_calloc(sprt->n_sprites + 1, sizeof(t_mlx_img *));
	sprt->sprite[0] = img_from_file_2(mlx->conn, "./assets/env/snow.xpm");
	sprt->sprite[1] = NULL;
	return (sprt);
}
