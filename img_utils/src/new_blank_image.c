/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_blank_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:26:32 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:03:22 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img_utils.h>

t_mlx_img	*new_blank_image(void *mlx_ptr, int width, int height)
{
	t_mlx_img	*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->height = height;
	img->width = width;
	img->addr = mlx_new_image(mlx_ptr, width, height);
	img->data = mlx_get_data_addr(img->addr, &img->bpp, \
						&img->line_size, &img->endian);
	clear_image(img);
	return (img);
}
