/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_by_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 02:54:31 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 03:41:32 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_mlx_img	*get_image_by_type(t_game_handler *game, char type)
{
	t_sprite	**sptr;

	sptr = game->sprites;
	while (*sptr)
	{
		if ((*sptr)->type == type)
			return ((*sptr)->sprite[0]);
		sptr++;
	}
	return (NULL);
}
