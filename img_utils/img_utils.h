/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:49:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/14 16:49:13 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H
# include <libft.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_mlx_img
{
	void	*addr;
	void	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_handler
{
	void		*conn;
	void		*win;
	t_mlx_img	*img;
}	t_mlx_handler;

int			img_offset(t_mlx_img img, int x, int y);
void		overlay_images(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void		override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void		clear_image(t_mlx_img *img);
void		destroy_t_mlx_img(t_mlx_handler *mlx, t_mlx_img *img);
t_mlx_img	img_from_file(void *mlx_ptr, char *rel_path);
t_mlx_img	*img_from_file_2(void *mlx_ptr, char *rel_path);
t_mlx_img	*new_blank_image(void *mlx_ptr, int width, int heigth);
#endif