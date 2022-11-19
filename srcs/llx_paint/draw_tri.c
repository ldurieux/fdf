#include "llx_paint_internal.h"
#include "llx_paint.h"

typedef struct s_bresenham_inter
{
	t_point	p1;
	t_point	p2;
	int		error;
	int		e2;
	t_point	delta;
	t_point	slope;
}	t_bresenham_inter;

static t_bresenham_inter	init_bresenham(t_point p1, t_point p2)
{
	t_bresenham_inter	res;

	res.p1 = p1;
	res.p2 = p2;
	res.delta.x = (int)ft_abs(p2.x - p1.x);
	res.delta.y = -(int)ft_abs(p2.y - p1.y);
	res.slope.x = -1 + (p1.x < p2.x) * 2;
	res.slope.y = -1 + (p1.y < p2.y) * 2;
	res.error = res.delta.x + res.delta.y;
	return (res);
}

static t_bresenham_inter	get_next_point(t_bresenham_inter d)
{
	while (1)
	{
		d.e2 = 2 * d.error;
		d.error += d.delta.y * (d.e2 >= d.delta.y) + d.delta.x * (d.e2 <= d.delta.x);
		d.p1.x += d.slope.x * (d.e2 >= d.delta.y);
		if (d.slope.y * (d.e2 <= d.delta.x))
		{
			d.p1.y += d.slope.y;
			return (d);
		}
	}
}

static void	draw_bottom_flat_triangle(t_llx_paint *paint, t_point p1, t_point p2, t_point p3)
{
	t_bresenham_inter	left;
	t_bresenham_inter	right;

	left = init_bresenham(p1, p2);
	right = init_bresenham(p1, p3);
	while (left.p1.y < p3.y)
	{
		draw_line(paint, left.p1, right.p1);
		left = get_next_point(left);
		right = get_next_point(right);
	}
	draw_line(paint, left.p1, right.p1);
}

static void	draw_top_flat_triangle(t_llx_paint *paint, t_point p1, t_point p2, t_point p3)
{
	t_bresenham_inter	left;
	t_bresenham_inter	right;

	left = init_bresenham(p1, p3);
	right = init_bresenham(p2, p3);
	while (left.p1.y < p3.y)
	{
		draw_line(paint, left.p1, right.p1);
		left = get_next_point(left);
		right = get_next_point(right);
	}
	draw_line(paint, left.p1, right.p1);
}

void	draw_tri(t_llx_paint *paint, t_point p1, t_point p2, t_point p3)
{
	t_point	p_tmp;
	t_color	save;

	save = paint->pen;
	paint->pen = paint->brush;
	if (p1.y == p2.y)
		draw_top_flat_triangle(paint, p1, p2, p3);
	else if (p2.y == p3.y)
		draw_bottom_flat_triangle(paint, p1, p2, p3);
	else
	{
		p_tmp.y = p2.y;
		p_tmp.x = (int)(p1.x + ((float)(p2.y - p1.y) / (float)(p3.y - p1.y))
					* (p3.x - p1.x));
		draw_bottom_flat_triangle(paint, p1, p2, p_tmp);
		draw_top_flat_triangle(paint, p2, p_tmp, p3);
	}
	paint->pen = save;
}
