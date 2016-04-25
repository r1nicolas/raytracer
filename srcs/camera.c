/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:20:12 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/18 17:56:15 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

/*
** Create a new camera with pos being the position of the camera, dir the
** direction it points, size the height of the screen and rot the angle of the
** camera.
*/

t_cam		new_cam(t_vec pos, t_vec dir, double size, double rot)
{
	t_cam		cam;
	double		**mat;

	cam.pos = pos;
	dir = new_vector_unit(dir.x, dir.y, dir.z);
	cam.dir = dir;
	cam.size = size;
	if (dir.x || dir.y)
		cam.right = new_vector_unit(-dir.y, dir.x, 0);
	else
		cam.right = new_vector_unit(1, 0, 0);
	cam.down = vector_cross_product(cam.dir, cam.right);
	if (cam.down.z > 0)
	{
		cam.down = vector_inverse(cam.down);
		cam.right = vector_inverse(cam.right);
	}
	mat = create_rotation_matrix(rot, cam.dir);
	cam.right = rotation_vector(mat, cam.right);
	cam.down = rotation_vector(mat, cam.down);
	free_matrix(mat);
	return (cam);
}

/*
** Create a ray, x and y being the position of the ray in the screen and cam the
** camera.
*/

t_ray		new_ray(int x, int y, t_cam cam)
{
	t_ray	ray;
	double	height;
	double	width;

	height = cam.size / (double)WINROW;
	width = cam.size / (double)WINCOL * (4.0 / 3.0);
	ray.dir = cam.dir;
	ray.point = cam.pos;
	ray.point.x = ray.point.x + width * cam.right.x * (x - WINCOL / 2)
		+ height * cam.down.x * (y - WINROW / 2);
	ray.point.y = ray.point.y + width * cam.right.y * (x - WINCOL / 2)
		+ height * cam.down.y * (y - WINROW / 2);
	ray.point.z = ray.point.z + width * cam.right.z * (x - WINCOL / 2)
		+ height * cam.down.z * (y - WINROW / 2);
	return (ray);
}
