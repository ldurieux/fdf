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
#include "llx_paint_internal.h"

static void	setup_paint(t_llx *llx, t_llx_paint *paint, t_fdf *fdf)
{
	t_llx_win	*win;

	win = llx->windows[0];
	*paint = (t_llx_paint){win->cache, Llx_Transparent, Llx_Black,
		(t_rect){0, 0, fdf->win_size.width, fdf->win_size.height}, 0};
	llx_paint_fill(paint);
	*paint = (t_llx_paint){win->cache, Llx_Transparent, Llx_White,
		(t_rect){0, 0, fdf->win_size.width, fdf->win_size.height}, 0};
}

static void	draw_fdf_points(t_llx_paint *paint, register t_point *pts,
						register t_color *cols, size_t count)
{
	register t_point	*end;
	uint32_t			*img_ptr;
	t_img_data			data;
	register size_t		line_size;
	register t_rect		bounds;

	bounds = paint->bounds;
	bounds.width = bounds.x + bounds.width;
	bounds.height = bounds.y + bounds.height;
	img_ptr = (uint32_t *)mlx_get_data_addr(paint->img, &data.pixel_bits,
			&data.line_bytes, &data.endian);
	line_size = data.line_bytes / 4;
	end = pts + count;
	while (pts != end)
	{
		if (pts->x >= 0 && pts->y >= 0
			&& pts->x < bounds.width
			&& pts->y < bounds.height)
			img_ptr[pts->y * line_size + pts->x] = cols->ucolor;
		pts++;
		cols++;
	}
}

static void	draw_fdf_lines(t_llx_paint *paint, register t_point *pts,
						size_t count, t_fdf *fdf)
{
	register t_point	*end;
	register t_color	*colors;
	register t_size		map_size;
	register size_t		idx;

	idx = 0;
	colors = fdf->colors;
	map_size = fdf->map_size;
	end = pts + (count - map_size.width);
	while (pts != end)
	{
		paint->pen = *colors;
		if (idx % map_size.width < map_size.width - 1)
			llx_paint_line(paint, *pts, *(pts + 1));
		llx_paint_line(paint, *pts, *(pts + map_size.width));
		pts++;
		colors++;
		idx++;
	}
}

static void	draw_fdf(t_llx_paint *paint, t_fdf *fdf, t_point *points)
{
	size_t	idx;
	size_t	count;
	t_size	map_size;

	map_size = fdf->map_size;
	count = map_size.width * map_size.height;
	if (fdf->flags & Fdf_points_only)
		draw_fdf_points(paint, points, fdf->colors, count);
	else
		draw_fdf_lines(paint, points, count, fdf);
}

int	fdf_on_loop(t_llx *llx)
{
	t_llx_paint	paint;
	t_point		*points;

	fdf_while_key_down(llx->windows[0], llx->data);
	setup_paint(llx, &paint, llx->data);
	if (!fdf_project_points(llx->data, &points))
		return (0);
	draw_fdf(&paint, llx->data, points);
	free(points);
	return (1);
}
