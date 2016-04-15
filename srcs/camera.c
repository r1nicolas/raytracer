/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:20:12 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/15 18:39:42 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdlib.h>

t_cam		get_cam(t_vec pos, t_vec u, double size, double rot)
{
	t_cam		cam;
	double		**mat;

	cam.pos = pos;
	u = unit_vect(u.x, u.y, u.z);
	cam.dir = u;
	cam.size = size;
	if (u.x || u.y)
		cam.right = unit_vect(-u.y, u.x, 0);
	else
		cam.right = unit_vect(1, 0, 0);
	cam.down = cross_prod(cam.dir, cam.right);
	if (cam.down.z > 0)
	{
		cam.down = mult_scalar(cam.down, -1);
		cam.right = mult_scalar(cam.right, -1);
	}
	mat = get_rot(rot, cam.dir);
	apply_rot(mat, &(cam.right));
	apply_rot(mat, &(cam.down));
	free(mat[0]);
	free(mat[1]);
	free(mat[2]);
	free(mat);
	return (cam);
}

t_ray		get_ray(int x, int y, t_cam cam)
{
	t_ray	r;
	double	height;
	double	width;

	height = cam.size / (double)WINROW;
	width = cam.size / (double)WINCOL * (4.0 / 3.0);
	r.dir = cam.dir;
	r.point = cam.pos;
	r.point.x = r.point.x + width * cam.right.x * (x - WINCOL / 2)
		+ height * cam.down.x * (y - WINROW / 2);
	r.point.y = r.point.y + width * cam.right.y * (x - WINCOL / 2)
		+ height * cam.down.y * (y - WINROW / 2);
	r.point.z = r.point.z + width * cam.right.z * (x - WINCOL / 2)
		+ height * cam.down.z * (y - WINROW / 2);
	return (r);
}
