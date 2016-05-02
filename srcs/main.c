/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/26 20:10:31 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <unistd.h>
#include <stdlib.h>
#include <SDL.h>

static int	*image_generation(void)
{
	int				*pixels;
	int				i;
	int				j;
	t_ray			ray;

	pixels = (int *)malloc(WINROW * WINCOL * sizeof(int));
	i = 0;
	while (i < WINCOL)
	{
		j = 0;
		while (j < WINROW)
		{
			ray = new_ray(i, j, g_scene.cam);
			pixels[j * WINCOL + i] = get_color(ray, g_scene, 0);
			j++;
		}
		i++;
	}
	return (pixels);
}

t_sdl		new_sdl_data(void)
{
	t_sdl			sdl_data;

	SDL_Init(SDL_INIT_VIDEO);
	sdl_data.window = SDL_CreateWindow("Raytracer", SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED, WINCOL,
										WINROW, SDL_WINDOW_OPENGL);
	if (!sdl_data.window)
		put_error(SDL_GetError());
	sdl_data.renderer = SDL_CreateRenderer(sdl_data.window, -1,
											SDL_RENDERER_ACCELERATED);
	if (!sdl_data.renderer)
		put_error(SDL_GetError());
	sdl_data.texture = SDL_CreateTexture(sdl_data.renderer,
											SDL_PIXELFORMAT_ARGB8888,
											SDL_TEXTUREACCESS_STATIC, WINCOL,
											WINROW);
	if (!sdl_data.texture)
		put_error(SDL_GetError());
	return (sdl_data);
}

void		delete_sdl_data(t_sdl sdl_data)
{
	SDL_DestroyTexture(sdl_data.texture);
	SDL_DestroyRenderer(sdl_data.renderer);
	SDL_DestroyWindow(sdl_data.window);
}

int			main(int ac, char **av)
{
	t_sdl			sdl_data;
	int				quit;
	SDL_Event		event;
	int				*pixels;

	if (ac != 2)
		put_error("usage: ./raytracer scene\n");
	create_scene(av[1]);
	sdl_data = new_sdl_data();
	pixels = image_generation();
	SDL_UpdateTexture(sdl_data.texture, NULL, pixels, WINCOL * sizeof(Uint32));
	SDL_RenderClear(sdl_data.renderer);
	SDL_RenderCopy(sdl_data.renderer, sdl_data.texture, NULL, NULL);
	SDL_RenderPresent(sdl_data.renderer);
	quit = 0;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			quit = 1;
	}
	free(pixels);
	delete_sdl_data(sdl_data);
	SDL_Quit();
	return (0);
}
