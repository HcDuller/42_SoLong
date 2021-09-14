/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:19:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 20:46:49 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <img_utils.h>

t_mlx_img	img_from_file(void *mlx_ptr, char *rel_path)
{
	t_mlx_img	img;

	img.addr = mlx_xpm_file_to_image(mlx_ptr, rel_path, \
									&img.width, &img.height);
	img.data = mlx_get_data_addr(img.addr, &img.bpp, \
								&img.line_size, &img.endian);
	return (img);
}
