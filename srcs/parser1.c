/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 16:36:53 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/18 17:53:48 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

struct s_scene	g_scene;

/*
** Initialize the scene.
*/

static void		init_scene(void)
{
	t_vec			pos;
	t_vec			u;

	pos = new_vector(1, 1, 1);
	u = new_vector_unit(-1, -1, -1);
	g_scene.cam = new_cam(pos, u, 1, 0);
	g_scene.list = NULL;
	g_scene.light = NULL;
}

/*
** Verify if the given line is valid according to the format.
** Write an error message and quit the program otherwise.
*/

static void		is_valid(char **split)
{
	char			*tab_type[7];
	int				i;

	create_tab_type(tab_type);
	if (strcmp(split[0], ">") != 0)
	{
		write(2, "parse error near ", 17);
		write(2, split[0], strlen(split[0]));
		put_error("\n");
	}
	i = 0;
	if (split[1])
	{
		while (i < 7)
		{
			if (strcmp(tab_type[i], split[1]) == 0)
				return ;
			i++;
		}
		write(2, "parse error near ", 17);
		write(2, split[1], strlen(split[1]));
		put_error("\n");
	}
}

/*
** Parse a line.
*/

static void		parse_line(char **split)
{
	t_func_parse	tab_func_parse[7];
	char			*tab_type[7];
	int				i;

	create_tab_type(tab_type);
	create_tab_func_parse(tab_func_parse);
	i = 0;
	while (i < 7)
	{
		if (strcmp(tab_type[i], split[1]) == 0)
			tab_func_parse[i](split);
		i++;
	}
}

/*
** Open the file given in parameter quit in case of invalide file or error.
*/

static int		open_file(char *path)
{
	struct stat		file_st;
	int				fd;

	if (stat(path, &file_st) == 0 && S_ISDIR(file_st.st_mode))
		put_error("directory is not a valid scene.\n");
	if ((fd = open(path, O_RDONLY)) == -1)
		put_error("can't access to the file.\n");
	return (fd);
}

/*
** Create the scene using the file given in parameter.
*/

void			create_scene(char *path)
{
	int				fd;
	char			**split;
	char			*line;
	int				ret;

	init_scene();
	fd = open_file(path);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (line != NULL)
		{
			if (line[0] != '#' && (split = strsplit(line, ' ')) != NULL)
			{
				is_valid(split);
				parse_line(split);
				free_split(split);
			}
			free(line);
		}
	}
}
