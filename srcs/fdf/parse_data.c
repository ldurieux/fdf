/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:54 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:29:55 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_memcnt(const void *mem, size_t len, char chr)
{
	size_t		res;
	const char	*str;
	const char	*end;

	str = mem;
	end = str + len;
	res = 0;
	while (str < end)
	{
		if (*str++ == chr)
		{
			res++;
			while (*str++ == chr)
				;
		}
	}
	return (res);
}

static t_rgba	color_from_hex(char *data, char **end)
{
	size_t	read;
	t_color	color;
	uint8_t	val;

	color.ucolor = 0;
	read = 0;
	while (*data
		&& (*data >= '0' && *data <= '9')
		|| (*data >= 'a' && *data <= 'f')
		|| (*data >= 'A' && *data <= 'F'))
	{
		val = *data - '0';
		if (*data >= 'a')
			val = *data - 'a' + 10;
		else if (*data >= 'A')
			val = *data - 'A' + 10;
		color.ucolor = (color.ucolor << 4) + val;
		read++;
		data++;
	}
	*end = data;
	return (color.rgba);
}

static int	parse_values(char *file, t_vec3 *points, t_color *colors,
					t_size size)
{
	size_t	idx;
	size_t	count;
	t_rgba	c;

	idx = (size_t)-1;
	count = (size_t)size.width * (size_t)size.height;
	c.a = 0;
	while (++idx < count)
	{
		points[idx].x = idx / (size_t)size.width;
		points[idx].z = idx % (size_t)size.width;
		points[idx].y = -ft_strtoll(file, &file);
		if (*file == ',')
		{
			file += 3;
			colors[idx].rgba = color_from_hex(file, &file);
		}
		else
			colors[idx].ucolor = Llx_White;
	}
	return (1);
}

static void	center_values(t_vec3 *points, t_size size)
{
	size_t	idx;
	size_t	count;

	idx = (size_t)-1;
	count = size.width * size.height;
	while (++idx < count)
	{
		points[idx].x -= size.width / 2;
		points[idx].z -= size.height / 2;
	}
}

int	fdf_parse_data(char *data, t_vec3 **points, t_color **colors, t_size *size)
{
	size_t	mem_size;

	while (ft_is_whitespace(*data))
		*data++;
	mem_size = ft_strlen(data);
	size->height = (int32_t)ft_memcnt(data, mem_size, '\n');
	mem_size = (size_t)ft_memchr(data, '\n', mem_size) - (size_t)data;
	size->width = (int32_t)ft_memcnt(data, mem_size, ' ') + 1;
	*points = malloc(sizeof(t_vec3) * (size_t)size->width
			* (size_t)size->height);
	*colors = malloc(sizeof(t_color) * (size_t)size->width
			* (size_t)size->height);
	if (!*points || !*colors)
	{
		free(*points);
		free(*colors);
		return (0);
	}
	if (!parse_values(data, *points, *colors, *size))
		return (0);
	center_values(*points, *size);
	return (1);
}
