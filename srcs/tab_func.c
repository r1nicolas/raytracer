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

void	instance_func(char **tab)
{
	tab[0] = "plane";
	tab[1] = "sphere";
	tab[2] = "cylinder";
	tab[3] = "cone";
	tab[4] = "camera";
	tab[5] = "spot";
	tab[6] = "quadric";
}

void	instance_funcf(t_parse *tabf)
{
	tabf[0] = push_plane;
	tabf[1] = push_sphere;
	tabf[2] = push_cylinder;
	tabf[3] = push_cone;
	tabf[4] = push_cam;
	tabf[5] = push_spot;
	tabf[6] = push_quad;
}

void	instance_funct(t_func *funct)
{
	funct[0] = int_plane;
	funct[1] = int_sphere;
	funct[2] = int_cylinder;
	funct[3] = cone_inter;
	funct[4] = int_quad;
}

void	instance_funct2(t_func2 *funct)
{
	funct[0] = sh_plane;
	funct[1] = sh_sphere;
	funct[2] = sh_cylinder;
	funct[3] = cone_shadow;
	funct[4] = sh_quad;
}
