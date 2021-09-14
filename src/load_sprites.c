/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:47:42 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 19:38:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_sprite	**load_sprites(t_mlx_handler *mlx)
{
	t_sprite	**assets;

	assets = ft_calloc(7, sizeof(t_sprite *));
	assets[0] = load_snow(mlx);
	assets[1] = load_tree(mlx);
	assets[2] = load_meat(mlx);
	assets[3] = load_player(mlx);
	assets[4] = load_exit(mlx);
	assets[5] = load_enemy(mlx);
	assets[6] = NULL;
	return (assets);
}
