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

int		main(int ac, char **av)
{
	SDL_Window		*window;
	int				quit;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
	int				*pixels;
	int				i;
	int				j;
	t_ray			ray;

	if (ac != 2)
		put_error("usage: ./raytracer scene\n");
	pixels = (int *)malloc(WINROW * WINCOL * sizeof(int));
	create_scene(av[1]);
	SDL_Init(SDL_INIT_VIDEO);
	if (!(window = SDL_CreateWindow("Raytracer",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									WINCOL,
									WINROW,
									SDL_WINDOW_OPENGL)))
		put_error(SDL_GetError());
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTexture(renderer,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								WINCOL,
								WINROW);
	quit = 0;
	i = 0;
	while (i < WINCOL)
	{
		j = 0;
		while (j < WINROW)
		{
			ray = new_ray(i, j, g_scene.cam);
			pixels[j * WINCOL + i] = get_color(ray, g_scene);
			j++;
		}
		i++;
	}
	SDL_UpdateTexture(texture, NULL, pixels, WINCOL * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			quit = 1;
	}
	free(pixels);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
