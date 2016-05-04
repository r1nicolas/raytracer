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

int			camera_move(SDL_Event event)
{
	static int		mode = 1;

	if (event.type == SDL_KEYDOWN && mode == 1)
	{
		if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_q)
			return (cam_move(g_scene.cam.right, -0.1));
		if (event.key.keysym.sym == SDLK_d)
			return (cam_move(g_scene.cam.right, 0.1));
		if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_z)
			return (cam_move(g_scene.cam.dir, 0.1));
		if (event.key.keysym.sym == SDLK_s)
			return (cam_move(g_scene.cam.dir, -0.1));
		if (event.key.keysym.sym == SDLK_r)
			return (cam_move(g_scene.cam.down, -0.1));
		if (event.key.keysym.sym == SDLK_f)
			return (cam_move(g_scene.cam.down, 0.1));
		if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2)
			mode = 2;
	}
	return (0);
}