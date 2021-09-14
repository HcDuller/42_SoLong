/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:04:40 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/02 12:04:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img_utils.h>

void	clear_image(t_mlx_img *img)
{
	int	i_x;
	int	i_y;

	i_y = 0;
	while (i_y < img->height)
	{
		i_x = 0;
		while (i_x < img->width)
		{
			*(unsigned int *)(img->data + img_offset(*img, i_x, i_y)) = \
			0xff000000;
			i_x++;
		}
		i_y++;
	}
}
