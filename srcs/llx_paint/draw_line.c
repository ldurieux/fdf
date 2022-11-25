/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:25 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:28 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint_internal.h"
#include "llx_paint.h"
#include <math.h>

#define A 0
#define R 1
#define G 2
#define B 3

static uint32_t	color_ratio(t_rgba start, t_rgba end, float ratio)
{
	t_color	color;

	color.rgba.a = start.a + ((float)end.a - (float)start.a) * ratio;
	color.rgba.r = start.r + ((float)end.r - (float)start.r) * ratio;
	color.rgba.g = start.g + ((float)end.g - (float)start.g) * ratio;
	color.rgba.b = start.b + ((float)end.b - (float)start.b) * ratio;
	return (color.ucolor);
}

static uint32_t	get_color(t_llx_paint *paint, t_point curr, t_point p1,
						t_point p2)
{
	float		dist_p1_p2;
	float		dist_curr_p2;
	float		ratio;
	t_pointF	tmp;

	if ((paint->flags & Paint_Flag_Gradient) == 0)
		return (paint->pen.ucolor);
	if (paint->pen.ucolor == paint->gradient.ucolor)
		return (paint->pen.ucolor);
	tmp.x = p2.x - curr.x;
	tmp.y = p2.y - curr.y;
	dist_curr_p2 = sqrtf(tmp.x * tmp.x + tmp.y * tmp.y);
	tmp.x = p2.x - p1.x;
	tmp.y = p2.y - p1.y;
	dist_p1_p2 = sqrtf(tmp.x * tmp.x + tmp.y * tmp.y);
	ratio = (dist_p1_p2 - dist_curr_p2) / dist_p1_p2;
	return (color_ratio(paint->pen.rgba, paint->gradient.rgba, ratio));
}

//Bresenham's line algorithm
//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
static void	draw_bresenham_line(t_llx_paint *paint, t_point p1, t_point p2,
							t_point delta)
{
	t_point	slope;
	int		error;
	int		e2;
	int		cond[2];
	t_point	save_p1;

	save_p1 = p1;
	slope.x = -1 + (p1.x < p2.x) * 2;
	slope.y = -1 + (p1.y < p2.y) * 2;
	error = delta.x + delta.y;
	while (1)
	{
		blend_pixel(paint, p1.x, p1.y, get_color(paint, p1, save_p1, p2));
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = 2 * error;
		cond[0] = e2 >= delta.y;
		cond[1] = e2 <= delta.x;
		if ((cond[0] && p1.x == p2.x)
			|| (cond[1] && p1.y == p2.y))
			break ;
		error += delta.y * cond[0] + delta.x * cond[1];
		p1.x += slope.x * cond[0];
		p1.y += slope.y * cond[1];
	}
}

static void	draw_simple_line(t_llx_paint *paint, t_point p1, t_point p2,
						t_point delta)
{
	int		x;
	int		y;
	int32_t	swap;

	if (p1.x > p2.x)
	{
		swap = p1.x;
		p1.x = p2.x;
		p2.x = swap;
	}
	if (p1.y > p2.y)
	{
		swap = p1.y;
		p1.y = p2.y;
		p2.y = swap;
	}
	y = p1.y - (delta.x == 0);
	x = p1.x - (delta.x != 0);
	if (delta.x == 0)
		while (++y <= p2.y)
			blend_pixel(paint, x, y, get_color(paint, (t_point){x, y}, p1, p2));
	else
		while (++x <= p2.x)
			blend_pixel(paint, x, y, get_color(paint, (t_point){x, y}, p1, p2));
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
