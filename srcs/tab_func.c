/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:45:36 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/19 19:00:07 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

/*
** All this functions fill the appropriate arrays.
*/

void	create_tab_type(char **tab)
{
	tab[0] = "plane";
	tab[1] = "sphere";
	tab[2] = "cylinder";
	tab[3] = "cone";
	tab[4] = "camera";
	tab[5] = "spot";
	tab[6] = "quadric";
}

void	create_tab_func_parse(t_func_parse *tab)
{
	tab[0] = parse_plane;
	tab[1] = parse_sphere;
	tab[2] = parse_cylinder;
	tab[3] = parse_cone;
	tab[4] = parse_camera;
	tab[5] = parse_spot;
	tab[6] = parse_quadric;
}

void	create_tab_func_inter(t_func_inter *tab)
{
	tab[0] = plane_inter;
	tab[1] = sphere_inter;
	tab[2] = cylinder_inter;
	tab[3] = cone_inter;
	tab[4] = quadric_inter;
}

void	create_tab_func_shadow(t_func_shadow *tab)
{
	tab[0] = plane_shadow;
	tab[1] = sphere_shadow;
	tab[2] = cylinder_shadow;
	tab[3] = cone_shadow;
	tab[4] = quadric_shadow;
}
