/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 20:43:34 by tlepetit          #+#    #+#             */
/*   Updated: 2014/02/28 16:57:09 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

void			get_matrice(double **ret, double angle, t_vec ort)
{
	double		s;
	double		c;

	c = cos(angle);
	s = sin(angle);
	ret[0][0] = ort.x * ort.x + (1 - ort.x * ort.x) * c;
	ret[0][1] = ort.x * ort.y * (1 - c) - ort.z * s;
	ret[0][2] = ort.z * ort.x * (1 - c) + ort.y * s;
	ret[1][0] = ort.x * ort.y * (1 - c) + ort.z * s;
	ret[1][1] = ort.y * ort.y + (1 - ort.y * ort.y) * c;
	ret[1][2] = ort.y * ort.z * (1 - c) - ort.x * s;
	ret[2][0] = ort.z * ort.x * (1 - c) - ort.y * s;
	ret[2][1] = ort.y * ort.z * (1 - c) + ort.x * s;
	ret[2][2] = ort.z * ort.z + (1 - ort.z * ort.z) * c;
}

void			init_ret(double ***ret)
{
	(*ret) = (double**)malloc(3 * sizeof(double*));
	(*ret)[0] = (double*)malloc(3 * sizeof(double));
	(*ret)[1] = (double*)malloc(3 * sizeof(double));
	(*ret)[2] = (double*)malloc(3 * sizeof(double));
	(*ret)[0][0] = 1;
	(*ret)[1][1] = 1;
	(*ret)[2][2] = 1;
	(*ret)[0][1] = 0;
	(*ret)[0][2] = 0;
	(*ret)[1][0] = 0;
	(*ret)[1][2] = 0;
	(*ret)[2][0] = 0;
	(*ret)[2][1] = 0;
}

void			apply_rot(double **rot, t_vec *pt)
{
	t_vec		tmp;

	tmp.x = pt->x * rot[0][0] + pt->y * rot[0][1] + pt->z * rot[0][2];
	tmp.y = pt->x * rot[1][0] + pt->y * rot[1][1] + pt->z * rot[1][2];
	tmp.z = pt->x * rot[2][0] + pt->y * rot[2][1] + pt->z * rot[2][2];
	*pt = tmp;
}

double			**get_rot(double angle, t_vec ort)
{
	double		**ret;

	init_ret(&ret);
	if (angle != 0)
		get_matrice(ret, angle, ort);
	return (ret);
}

double			**inv_mat(double **rot)
{
	double	**inv;

	inv = malloc(sizeof(double*) * 3);
	inv[0] = malloc(sizeof(double) * 3);
	inv[1] = malloc(sizeof(double) * 3);
	inv[2] = malloc(sizeof(double) * 3);
	inv[0][0] = rot[1][1] * rot[2][2] - rot[1][2] * rot[2][1];
	inv[1][0] = rot[1][2] * rot[2][0] - rot[2][2] * rot[1][0];
	inv[2][0] = rot[1][0] * rot[2][1] - rot[1][1] * rot[2][0];
	inv[0][1] = rot[2][1] * rot[0][2] - rot[2][2] * rot[0][1];
	inv[1][1] = rot[2][2] * rot[0][0] - rot[0][2] * rot[2][0];
	inv[2][1] = rot[2][0] * rot[0][1] - rot[2][1] * rot[0][0];
	inv[0][2] = rot[0][1] * rot[1][2] - rot[0][2] * rot[1][1];
	inv[1][2] = rot[0][2] * rot[1][0] - rot[0][0] * rot[1][2];
	inv[2][2] = rot[0][0] * rot[1][1] - rot[0][1] * rot[1][0];
	return (inv);
}
