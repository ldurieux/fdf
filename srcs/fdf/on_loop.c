/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:56 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:29:57 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_paint(t_llx *llx, t_llx_paint *paint, t_fdf *fdf)
{
	t_llx_win	*win;

	win = llx->windows[0];
	*paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_Black,
		(t_rect){0, 0, fdf->win_size.width, fdf->win_size.height}, 0};
	llx_paint_fill(paint);
	*paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_White,
		(t_rect){0, 0, fdf->win_size.width, fdf->win_size.height}, 0};
}

static int	project_points(t_fdf *fdf, t_point **points)
{
	t_vec3		*projected;
	size_t		count;
	size_t		idx;
	t_mat4x4	mat_rot;
	t_size		half_win_size;

	half_win_size = fdf->win_size;
	half_win_size.width /= 2;
	half_win_size.height /= 2;
	mat_rot = llx_rotation_matrix(fdf->rot.z, fdf->rot.y, fdf->rot.x);
	count = (size_t)fdf->map_size.width * (size_t)fdf->map_size.height;
	idx = (size_t)-1;
	projected = malloc(sizeof(t_vec3) * count);
	*points = malloc(sizeof(t_point) * count);
	if (!*points || !projected)
		return (free(points), free(projected), 0);
	while (++idx < count)
	{
		projected[idx] = fdf->points[idx];
		llx_project_vec3(projected + idx, &fdf->trans, &mat_rot,
			&fdf->proj_matrix);
		(*points)[idx] = llx_vec3_to_point(projected + idx, half_win_size);
	}
	return (free(projected), 1);
}

static void	draw_fdf(t_llx_paint *paint, t_fdf *fdf, t_point *points)
{
	int32_t	idx;
	int32_t	count;
	t_size	map_size;

	map_size = fdf->map_size;
	count = map_size.width * map_size.height;
	idx = -1;
	while (++idx < count)
	{
		paint->pen = fdf->colors[idx];
		if (idx % map_size.width != map_size.width - 1)
			llx_paint_line(paint, points[idx], points[idx + 1]);
		if (idx / map_size.width < map_size.height - 1)
			llx_paint_line(paint, points[idx], points[idx + map_size.width]);
	}
}

int	fdf_on_loop(t_llx *llx)
{
	t_llx_paint	paint;
	t_point		*points;

	setup_paint(llx, &paint, llx->data);
	if (!project_points(llx->data, &points))
		return (0);
	draw_fdf(&paint, llx->data, points);
	free(points);
	return (1);
}
