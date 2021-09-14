/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_t_mlx_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:51:42 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 20:46:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img_utils.h>

void	destroy_t_mlx_img(t_mlx_handler *mlx, t_mlx_img *img)
{
	mlx_destroy_image(mlx->conn, img->addr);
	free(img);
	img = NULL;
}
