/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 20:43:34 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/25 16:59:07 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

/*
** create and allocate matrix 3-3.
*/

static double	**new_matrix(void)
{
	double		**matrix;

	matrix = (double**)malloc(3 * sizeof(double*));
	matrix[0] = (double*)malloc(3 * sizeof(double));
	matrix[1] = (double*)malloc(3 * sizeof(double));
	matrix[2] = (double*)malloc(3 * sizeof(double));
	matrix[0][0] = 1;
	matrix[1][0] = 0;
	matrix[2][0] = 0;
	matrix[0][1] = 0;
	matrix[1][1] = 1;
	matrix[2][1] = 0;
	matrix[0][2] = 0;
	matrix[1][2] = 0;
	matrix[2][2] = 1;
	return (matrix);
}

/*
** Apply a rotation matric to a vector.
*/

t_vec			rotation_vector(double **mat, t_vec vector)
{
	t_vec		ret;

	ret.x = vector.x * mat[0][0] + vector.y * mat[0][1] + vector.z * mat[0][2];
	ret.y = vector.x * mat[1][0] + vector.y * mat[1][1] + vector.z * mat[1][2];
	ret.z = vector.x * mat[2][0] + vector.y * mat[2][1] + vector.z * mat[2][2];
	return (ret);
}

/*
** Create the rotation matrix of angle angle around the vector axe.
*/

double			**create_rotation_matrix(double angle, t_vec axe)
{
	double		**matrix;
	double		s;
	double		c;

	matrix = new_matrix();
	if (angle != 0)
	{
		c = cos(angle);
		s = sin(angle);
		matrix[0][0] = axe.x * axe.x + (1 - axe.x * axe.x) * c;
		matrix[0][1] = axe.x * axe.y * (1 - c) - axe.z * s;
		matrix[0][2] = axe.z * axe.x * (1 - c) + axe.y * s;
		matrix[1][0] = axe.x * axe.y * (1 - c) + axe.z * s;
		matrix[1][1] = axe.y * axe.y + (1 - axe.y * axe.y) * c;
		matrix[1][2] = axe.y * axe.z * (1 - c) - axe.x * s;
		matrix[2][0] = axe.z * axe.x * (1 - c) - axe.y * s;
		matrix[2][1] = axe.y * axe.z * (1 - c) + axe.x * s;
		matrix[2][2] = axe.z * axe.z + (1 - axe.z * axe.z) * c;
	}
	return (matrix);
}

/*
** Return the inverse of an invertible matrix.
*/

double			**matrix_inverse(double **mat)
{
	double	**inv;

	inv = new_matrix();
	inv[0][0] = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];
	inv[1][0] = mat[1][2] * mat[2][0] - mat[2][2] * mat[1][0];
	inv[2][0] = mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0];
	inv[0][1] = mat[2][1] * mat[0][2] - mat[2][2] * mat[0][1];
	inv[1][1] = mat[2][2] * mat[0][0] - mat[0][2] * mat[2][0];
	inv[2][1] = mat[2][0] * mat[0][1] - mat[2][1] * mat[0][0];
	inv[0][2] = mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1];
	inv[1][2] = mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2];
	inv[2][2] = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
	return (inv);
}
