#include "llx_paint_internal.h"
#include "llx_paint.h"

static void	plot(t_llx_paint *paint, int x, int y, float brightness)
{
	t_color	color;

	if (!is_in_bound(paint, x, y))
		return ;
	color = paint->pen;
	color.rgba.a = (int)((float)color.rgba.a * brightness);
	blend_pixel(paint, x, y, color.ucolor);
}

static float rfpart(float val)
{
	return (1 - (val - (float)(int)val));
}

static void	init(int *steep, t_point *p1, t_point *p2, float *gradient)
{
	t_point	delta;

	*steep = ft_abs(p2->y - p1->y) > ft_abs(p2->x - p1->x);
	if (*steep)
	{
		ft_swap(&p1->x, &p1->y, sizeof(int));
		ft_swap(&p2->x, &p2->y, sizeof(int));
	}
	if (p1->x > p2->x)
		ft_swap(p1, p2, sizeof(t_point));
	delta.x = p2->x - p1->x;
	delta.y = p2->y - p1->y;
	*gradient = (float)1.0;
	if (delta.x != 0)
		*gradient = (float)delta.y / (float)delta.x;
}

#define HALF 0.5

static int	draw_end_point(t_llx_paint *paint, t_point p, float gradient, int steep)
{
	int		x_end;
	float	y_end;
	float	x_gap;
	float	y_fpart;

	x_end = (int)((float)p.x + HALF);
	y_end = (float)p.y + gradient * (float)(x_end - p.x);
	x_gap = rfpart((float)p.x + (float)HALF);
	y_fpart = (y_end - (float)(int)y_end);
	if (steep)
	{
		plot(paint, (int)y_end, x_end, rfpart(y_end) * x_gap);
		plot(paint, (int)y_end + 1, x_end, y_fpart * x_gap);
	}
	else
	{
		plot(paint, x_end, (int)y_end, rfpart(y_end) * x_gap);
		plot(paint, x_end, (int)y_end + 1, y_fpart * x_gap);
	}
	return (x_end);
}

// Xiaolin Wu's line algorithm
// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
void	draw_line_aa(t_llx_paint *paint, t_point p1, t_point p2)
{
	int		steep;
	float	gradient;
	int		start;
	int		end;
	float	intery;

	init(&steep, &p1, &p2, &gradient);
	start = draw_end_point(paint, p1, gradient, steep);
	end = draw_end_point(paint, p2, gradient, steep);
	intery = (float)p1.y + gradient;
	if (steep)
	{
		while (++start < end)
		{
			plot(paint, (int)intery, start, rfpart(intery));
			plot(paint, (int)intery + 1, start, intery - (float)(int)intery);
			intery += gradient;
		}
	}
	else
	{
		while (++start < end)
		{
			plot(paint, start, (int)intery, rfpart(intery));
			plot(paint, start, (int)intery + 1, intery - (float)(int)intery);
			intery += gradient;
		}
	}
}
