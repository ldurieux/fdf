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
		if (*str++ == chr)
			res++;
	return (res);
}

static uint8_t	from_hex(char *bytes)
{
	uint8_t	res;

	if (bytes[0] < 'a')
		res = (uint8_t)((bytes[0] - '0') << 4);
	else
		res = (uint8_t)((bytes[0] - 'a' + 10) << 4);
	if (bytes[1] < 'a')
		res += (uint8_t)((bytes[0] - '0'));
	else
		res += (uint8_t)((bytes[0] - 'a' + 10));
	return (res);
}

static int	parse_values(char *file, t_vec3 *points, t_color *colors, t_size size)
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
		points[idx].y = ft_strtoll(file, &file);
		if (*file == ',')
		{
			file += 3;
			c.r = from_hex(file);
			c.g = from_hex(file + 2);
			c.b = from_hex(file + 4);
			colors[idx].rgba = c;
			file += 6;
		}
		else
			colors[idx].ucolor = Llx_White;
	}
	return (1);
}

int	parse_data(char *data, t_vec3 **points, t_color **colors, t_size *size)
{
	size_t	mem_size;

	mem_size = ft_strlen(data);
	size->height = (int32_t)ft_memcnt(data, mem_size, '\n');
	mem_size = (size_t)ft_memchr(data, '\n', mem_size) - (size_t)data;
	size->width = (int32_t)ft_memcnt(data, mem_size, ' ') + 1;
	*points = malloc(sizeof(t_vec3) * (size_t)size->width * (size_t)size->height);
	*colors = malloc(sizeof(t_color) * (size_t)size->width * (size_t)size->height);
	if (!*points || !*colors)
	{
		free(*points);
		free(*colors);
		return (0);
	}
	return (parse_values(data, *points, *colors, *size));
}
