/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:30:26 by rnicolas          #+#    #+#             */
/*   Updated: 2014/03/27 16:40:13 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <raytracer.h>
#include <libft.h>

static t_img	*final_img_data(void *img)
{
	static t_img	*img_dat;

	if (img_dat == NULL)
	{
		img_dat = malloc(sizeof(t_img));
		img_dat->add = mlx_get_data_addr(img, &(img_dat->bits),
			&(img_dat->line_size), &(img_dat->endian));
	}
	return (img_dat);
}

static void		change_pixel(int x, int y, t_img *img, int rgb)
{
	unsigned int	color;
	int				i;

	color = mlx_get_color_value(img->env->mlx, rgb);
	i = 0;
	if (img->endian == 0)
	{
		while (i < img->bits / 8)
		{
			*(img->add + img->line_size * y + x * img->bits / 8 + i) =
				*((char*)(&color) + i);
			i++;
		}
	}
}

void			change_image(t_env *env, int x, int y, int rgb)
{
	t_img			*img;

	img = final_img_data(env->img);
	img->env = env;
	change_pixel(x, y, img, rgb);
}
