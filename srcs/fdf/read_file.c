#include "fdf.h"

#define READ_SIZE	512

static char	*read_buf(int fd, int *error)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (READ_SIZE + 1));
	bytes_read = read(fd, buffer, READ_SIZE);
	if (bytes_read == -1)
		*error = 1;
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

static char	*list_to_buf(t_ftfrwlist *list)
{
	t_ftfrwlist_node	*node;
	char				*buf;
	size_t				mem_idx;

	mem_idx = 0;
	buf = malloc(sizeof(char) * (list->size * READ_SIZE + 1));
	if (!buf)
	{
		ft_frwlist_iter(list, free);
		ft_frwlist_delete(list);
		return (NULL);
	}
	node = list->first;
	while (node)
	{
		ft_memcpy(buf + mem_idx, node->value, READ_SIZE);
		mem_idx += READ_SIZE;
		free(node->value);
		node->value = NULL;
		node = node->next;
	}
	ft_frwlist_delete(list);
	return (buf);
}

static char	*read_fd(int fd)
{
	t_ftfrwlist *list;
	char		*buf;
	int			error;

	error = 0;
	list = ft_frwlist_new();
	if (!list)
		return (NULL);
	while (1)
	{
		buf = read_buf(fd, &error);
		if (error)
		{
			ft_frwlist_iter(list, free);
			ft_frwlist_delete(list);
			return (NULL);
		}
		if (!buf)
			break ;
		if (!ft_frwlist_push_back(list, buf))
		{
			ft_frwlist_iter(list, free);
			ft_frwlist_delete(list);
			return (NULL);
		}
	}
	return (list_to_buf(list));
}

int	fdf_read_file(char *path, t_vec3 **points, t_color **colors, t_size *size)
{
	int		fd;
	char	*data;
	int		res;

	if (!path || !points || !colors || !size)
		return (0);
	fd = open(path, O_RDONLY);
	if (read(fd, NULL, 0) != 0)
		return (0);
	data = read_fd(fd);
	if (!data)
		return (0);
	res = parse_data(data, points, colors, size);
	free(data);
	return (res);
}
