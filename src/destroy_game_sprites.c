/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:04:09 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 20:43:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	destroy_game_sprites(t_mlx_handler *mlx, t_sprite **spr)
{
	int	i;

	i = 0;
	while (spr[i])
	{
		destroy_sprite(mlx, spr[i]);
		i++;
	}
	free(spr);
	spr = NULL;
}
