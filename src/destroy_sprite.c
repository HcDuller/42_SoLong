/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:04:09 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 20:43:46 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	destroy_sprite(t_mlx_handler *mlx, t_sprite *spr)
{
	int	i;

	i = 0;
	while (spr->sprite[i])
	{
		destroy_t_mlx_img(mlx, spr->sprite[i]);
		i++;
	}
	free(spr->sprite);
	spr->sprite = NULL;
	free(spr);
}
