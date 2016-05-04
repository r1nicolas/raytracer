/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:21:48 by rnicolas          #+#    #+#             */
/*   Updated: 2016/05/04 18:21:49 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <raytracer.h>

static int	cam_move(t_vec dir, double l)
{
	g_scene.cam.pos = vector_add(g_scene.cam.pos, vector_scalar_mult(dir, l));
	return (1);
}

static int	cam_rot(int flag, double angle)
{
	double			**mat;

	if (flag == 1)
	{
		mat = create_rotation_matrix(angle,  g_scene.cam.down);
		g_scene.cam.dir = rotation_vector(mat, g_scene.cam.dir);
		g_scene.cam.right = rotation_vector(mat, g_scene.cam.right);
	}
	if (flag == 2)
	{
		mat = create_rotation_matrix(angle,  g_scene.cam.right);
		g_scene.cam.dir = rotation_vector(mat, g_scene.cam.dir);
		g_scene.cam.down = rotation_vector(mat, g_scene.cam.down);
	}
	if (flag == 3)
	{
		mat = create_rotation_matrix(angle,  g_scene.cam.dir);
		g_scene.cam.right = rotation_vector(mat, g_scene.cam.right);
		g_scene.cam.down = rotation_vector(mat, g_scene.cam.down);
	}
	free_matrix(mat);
	return (1);
}

int			camera_move(SDL_Event event)
{
	static int		mode = 1;

	if (event.type == SDL_KEYDOWN && mode == 1)
	{
		if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_q)
			return (cam_move(g_scene.cam.right, -0.1));
		else if (event.key.keysym.sym == SDLK_d)
			return (cam_move(g_scene.cam.right, 0.1));
		else if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_z)
			return (cam_move(g_scene.cam.dir, 0.1));
		else if (event.key.keysym.sym == SDLK_s)
			return (cam_move(g_scene.cam.dir, -0.1));
		else if (event.key.keysym.sym == SDLK_r)
			return (cam_move(g_scene.cam.down, -0.1));
		else if (event.key.keysym.sym == SDLK_f)
			return (cam_move(g_scene.cam.down, 0.1));
		else if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2)
			mode = 2;
	}
	else if (event.type == SDL_KEYDOWN && mode == 2)
	{
		if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_q)
			return (cam_rot(1, -0.1));
		else if (event.key.keysym.sym == SDLK_d)
			return (cam_rot(1, 0.1));
		else if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_z)
			return (cam_rot(2, 0.1));
		else if (event.key.keysym.sym == SDLK_s)
			return (cam_rot(2, -0.1));
		else if (event.key.keysym.sym == SDLK_r)
			return (cam_rot(3, 0.1));
		else if (event.key.keysym.sym == SDLK_t)
			return (cam_rot(3, -0.1));
		else if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1)
			mode = 1;
	}
	return (0);
}
