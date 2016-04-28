/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:35:19 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/19 19:04:36 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

/*
** Multiplies a color by a factor
*/

static int	color_mult(int color, double factor)
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

static int	color_add(int color1, int color2)
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

/*
** get the color at the intersection "inter" using the object list "list"
*/

static int	get_color_inter(t_inter inter, t_object_list *list)
{
	int		result;
	int		diffuse;
	int		specular;
	double	s_prod;
	int		spot_number;

	spot_number = count_light(inter.light_ray_list);
	result = color_mult(inter.color, 0.2);
	while (inter.light_ray_list)
	{
		s_prod = vector_dot_product(inter.normal, inter.light_ray_list->light.dir);
		if (s_prod < 0 && is_not_in_shadow(inter.pos, list,
										   inter.light_ray_list->light))
		{
			diffuse = color_mult(inter.color, -0.8 * s_prod / spot_number);
			s_prod = vector_dot_product(inter.refl, inter.light_ray_list->light.dir);
			specular = (s_prod > 0 ? 0 :
				color_mult(0xFFFFFF, 0.2 * pow(s_prod, 50)));
			result = color_add(result, diffuse);
			result = color_add(result, specular);
		}
		inter.light_ray_list = inter.light_ray_list->next;
	}
	return (result);
}

/*
** Return the color that appears on the screen using a ray.
*/

int			get_color(t_ray ray, t_scene sc, int n)
{
	t_inter			inter;
	t_object_list	*list;
	int				color;
/*	int				refl;
	t_ray			ray_refl;*/
	t_func_inter	tab_func_inter[5];

	(void)n;
	create_tab_func_inter(tab_func_inter);
	list = sc.list;
	inter.dist = NULL;
	inter.light_ray_list = NULL;
	while (list)
	{
		tab_func_inter[list->obj](&inter, list->e, ray, sc.light);
		list = list->next;
	}
	if (inter.dist == NULL)
		return (0);
	else
	{
		color = get_color_inter(inter, sc.list);
/*		if (n < 6 && inter.ref_val > 0)
		{
			ray_refl.point = inter.pos;
			ray_refl.dir = inter.refl;
			refl = get_color(ray_refl, sc, n + 1);
			refl = color_mult(refl, inter.ref_val);
			color = color_mult(color, 1 - inter.ref_val);
			color = color_add(color, refl);
		}*/
		free(inter.dist);
		free_light_ray_list(&inter);
		return (color);
	}
}
