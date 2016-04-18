/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:35:19 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/18 18:14:21 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>

/*
** Multiplies a color by a factor
*/

int		color_mult(int color, double factor)
{
	int		red;
	int		green;
	int		blue;

	red = color / 0x10000;
	red = red * factor;
	if (red < 0)
		red = 0;
	if (red > 0xff)
		red = 0xff;
	green = (color / 0x100) % 0x100;
	green = green * factor;
	if (green < 0)
		green = 0;
	if (green > 0xff)
		green = 0xff;
	blue = color % 0x100;
	blue = blue * factor;
	if (blue < 0)
		blue = 0;
	if (blue > 0xff)
		blue = 0xff;
	return (red * 0x10000 + green * 0x100 + blue);
}

/*
** Adds two colors together
*/

int		color_add(int color1, int color2)
{
	int		red;
	int		green;
	int		blue;

	red = color1 / 0x10000 + color2 / 0x10000;
	if (red > 0xff)
		red = 0xff;
	green = (color1 / 0x100) % 0x100 + (color2 / 0x100) % 0x100;
	if (green > 0xff)
		green = 0xff;
	blue = color1 % 0x100 + color2 % 0x100;
	if (blue > 0xff)
		blue = 0xff;
	return (red * 0x10000 + green * 0x100 + blue);
}




int		get_color_inter(t_inter inter, t_object_list *list)
{
	int		result;
	int		diffuse;
	int		specular;
	double	s_prod;
	int		spot_number;

	spot_number = count_spot(inter.light_ray_list);
	result = color_mult(inter.color, 0.2);
	while (inter.light_ray_list)
	{
		s_prod = scalar_prod(inter.normal, inter.light_ray_list->light.dir);
		if (s_prod < 0 && shadow(inter.inter, list, inter.light_ray_list))
		{
			diffuse = color_mult(inter.color, -0.8 * s_prod / spot_number);
			s_prod = scalar_prod(inter.refl, inter.light_ray_list->light.dir);
			if (s_prod > 0)
				specular = 0;
			else
				specular = color_mult(0xFFFFFF, 0.2 * pow(s_prod, 50));
			result = color_add(result, diffuse);
			result = color_add(result, specular);
		}
		inter.light_ray_list = inter.light_ray_list->next;
	}
	return (result);
}
