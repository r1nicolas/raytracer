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
	tab[0] = push_plane;
	tab[1] = push_sphere;
	tab[2] = push_cylinder;
	tab[3] = push_cone;
	tab[4] = push_cam;
	tab[5] = push_spot;
	tab[6] = push_quad;
}

void	create_tab_func_inter(t_func_inter *tab)
{
	tab[0] = int_plane;
	tab[1] = int_sphere;
	tab[2] = cylinder_inter;
	tab[3] = cone_inter;
	tab[4] = int_quad;
}

void	create_tab_func_shadow(t_func_shadow *tab)
{
	tab[0] = sh_plane;
	tab[1] = sh_sphere;
	tab[2] = cylinder_shadow;
	tab[3] = cone_shadow;
	tab[4] = sh_quad;
}
