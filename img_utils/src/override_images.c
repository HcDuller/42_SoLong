/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   override_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:08:38 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/01 16:19:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img_utils.h>

void	override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y)
{
	char	*dst_pix;
	char	*src_pix;
	int		i_x[2];
	int		i_y[2];

	dst_pix = dst->data;
	src_pix = src->data;
	i_y[0] = 0;
	while (i_y[0] < src->height)
	{
		i_x[0] = 0;
		while (i_x[0] < src->width)
		{
			i_x[1] = i_x[0] + x;
			i_y[1] = i_y[0] + y;
			*(unsigned int *)(dst_pix + img_offset(*dst, i_x[1], i_y[1])) = \
			*(unsigned int *)(src_pix + img_offset(*src, i_x[0], i_y[0]));
			i_x[0]++;
		}
		i_y[0]++;
	}
}
