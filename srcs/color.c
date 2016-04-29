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
	red = TEST_COLOR(red);
	green = (color / 0x100) % 0x100;
	green = green * factor;
	green = TEST_COLOR(green);
	blue = color % 0x100;
	blue = blue * factor;
	blue = TEST_COLOR(blue);
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
	red = TEST_COLOR(red);
	green = (color1 / 0x100) % 0x100 + (color2 / 0x100) % 0x100;
	green = TEST_COLOR(green);
	blue = color1 % 0x100 + color2 % 0x100;
	blue = TEST_COLOR(blue);
	return (red * 0x10000 + green * 0x100 + blue);
}

/*
** Return the color of refraction and reflection.
** TO DO REFRACTION
*/

static int	get_color_reflection_refraction(t_inter inter, int n)
{
	int		result;

	result = 0;
	if (n < 6 && inter.refl_val > 0)
	{
		result = get_color((t_ray){inter.pos, inter.refl}, g_scene, n + 1);
		result = color_mult(result, inter.refl_val);
	}
	return (result);
}

/*
** get the color at the intersection "inter" using the object list "list"
*/

static int	get_color_inter(t_inter inter, int n)
{
	int		result;
	int		temp;
	double	dot;
	int		spot_number;

	spot_number = count_light(inter.light_list);
	result = color_mult(inter.color, 0.2 * (1 - inter.refl_val));
	while (inter.light_list)
	{
		dot = vector_dot_product(inter.normal, inter.light_list->light.dir);
		if (dot < 0 && is_not_in_shadow(inter.pos, inter.light_list->light))
		{
			temp = color_mult(inter.color,
							-0.8 * dot / spot_number * (1 - inter.refl_val));
			result = color_add(result, temp);
			dot = vector_dot_product(inter.refl, inter.light_list->light.dir);
			temp = (dot > 0 ? 0 : color_mult(0xFFFFFF, 0.2 * pow(dot, 50)));
			result = color_add(result, temp);
		}
		inter.light_list = inter.light_list->next;
	}
	temp = get_color_reflection_refraction(inter, n);
	result = color_add(result, temp);
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
	t_func_inter	tab_func_inter[5];

	create_tab_func_inter(tab_func_inter);
	list = sc.list;
	inter.dist = NULL;
	inter.light_list = NULL;
	while (list)
	{
		tab_func_inter[list->obj](&inter, list->e, ray, sc.light);
		list = list->next;
	}
	if (inter.dist == NULL)
		return (0);
	else
	{
		color = get_color_inter(inter, n);
		free(inter.dist);
		free_light_ray_list(&inter);
		return (color);
	}
}
