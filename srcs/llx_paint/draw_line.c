#include "llx_paint_internal.h"
#include "llx_paint.h"

//Bresenham's line algorithm
//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
static void	draw_bresenham_line(t_llx_paint *paint, t_point p1, t_point p2, t_point delta)
{
	t_point	slope;
	int		error;
	int		e2;
	int		cond1;
	int		cond2;

	slope.x = -1 + (p1.x < p2.x) * 2;
	slope.y = -1 + (p1.y < p2.y) * 2;
	error = delta.x + delta.y;
	while (1)
	{
		blend_pixel(paint, p1.x, p1.y, paint->pen.ucolor);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = 2 * error;
		cond1 = e2 >= delta.y;
		cond2 = e2 <= delta.x;
		if (cond1 && p1.x == p2.x ||
			cond2 && p1.y == p2.y)
			break ;
		error += delta.y * cond1 + delta.x * cond2;
		p1.x += slope.x * cond1;
		p1.y += slope.y * cond2;
	}
}

static void	draw_simple_line(t_llx_paint *paint, t_point p1, t_point p2, t_point delta)
{
	int	x;
	int	y;

	if (p1.x > p2.x)
		ft_swap(&p1.x, &p2.x, sizeof(int));
	if (p1.y > p2.y)
		ft_swap(&p1.y, &p2.y, sizeof(int));
	y = p1.y;
	x = p1.x;
	if (delta.x == 0)
		while (y <= p2.y)
			blend_pixel(paint, x, y++, paint->pen.ucolor);
	else
		while (x <= p2.x)
			blend_pixel(paint, x++, y, paint->pen.ucolor);
}

void	draw_line(t_llx_paint *paint, t_point p1, t_point p2)
{
	t_point	delta;

	delta.x = (int)ft_abs(p2.x - p1.x);
	delta.y = -(int)ft_abs(p2.y - p1.y);
	if (delta.x == 0 || delta.y == 0)
		draw_simple_line(paint, p1, p2, delta);
	else
		draw_bresenham_line(paint, p1, p2, delta);
}
