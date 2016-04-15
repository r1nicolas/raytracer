/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:35:19 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/15 18:40:27 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>

int		color_mult(int color, double fac)
{
	int		red;
	int		green;
	int		blue;

	red = color / 0x10000;
	red = red * fac;
	if (red < 0)
		red = 0;
	if (red > 0xff)
		red = 0xff;
	green = (color / 0x100) % 0x100;
	green = green * fac;
	if (green < 0)
		green = 0;
	if (green > 0xff)
		green = 0xff;
	blue = color % 0x100;
	blue = blue * fac;
	if (blue < 0)
		blue = 0;
	if (blue > 0xff)
		blue = 0xff;
	return (red * 0x10000 + green * 0x100 + blue);
}

int		color_add(int col1, int col2)
{
	int		red;
	int		green;
	int		blue;

	red = col1 / 0x10000 + col2 / 0x10000;
	if (red > 0xff)
		red = 0xff;
	green = (col1 / 0x100) % 0x100 + (col2 / 0x100) % 0x100;
	if (green > 0xff)
		green = 0xff;
	blue = col1 % 0x100 + col2 % 0x100;
	if (blue > 0xff)
		blue = 0xff;
	return (red * 0x10000 + green * 0x100 + blue);
}

int		get_color_inter(t_inter inter, t_objlist *lst)
{
	int		amb;
	int		diff;
	int		spec;
	double	prod;
	int		count;

	count = count_spot(inter.info);
	amb = color_mult(inter.color, 0.2);
	while (inter.info)
	{
		prod = scalar_prod(inter.normal, inter.info->light.dir);
		if (prod < 0 && shadow(inter.inter, lst, inter.info))
		{
			diff = color_mult(inter.color, -0.8 * prod / count);
			prod = scalar_prod(inter.refl, inter.info->light.dir);
			if (prod > 0)
				spec = 0;
			else
				spec = color_mult(0xFFFFFF, 0.2 * pow(prod, 50));
			amb = color_add(amb, diff);
			amb = color_add(amb, spec);
		}
		inter.info = inter.info->next;
	}
	return (amb);
}
