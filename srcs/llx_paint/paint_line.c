/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:41 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:43 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"
#include "llx_paint_internal.h"

#define INSIDE	0x0
#define LEFT	0x1
#define RIGHT	0x2
#define BOTTOM	0x4
#define TOP		0x8

static uint8_t	out_code(t_rect b, t_point p)
{
	uint8_t	res;

	res = INSIDE;
	if (p.x < b.x)
		res |= LEFT;
	else if (p.x > b.width)
		res |= RIGHT;
	if (p.y < b.y)
		res |= TOP;
	else if (p.y > b.height)
		res |= BOTTOM;
	return (res);
}

static void	line_clip_inside(t_point *p[3], uint8_t code, t_rect b)
{
	if (code & BOTTOM)
	{
		p[0]->x = p[1]->x + (p[2]->x - p[1]->x) * (b.height - p[1]->y)
			/ (p[2]->y - p[1]->y);
		p[0]->y = b.height;
	}
	else if (code & TOP)
	{
		p[0]->x = p[1]->x + (p[2]->x - p[1]->x) * (b.y - p[1]->y)
			/ (p[2]->y - p[1]->y);
		p[0]->y = b.y;
	}
	else if (code & RIGHT)
	{
		p[0]->y = p[1]->y + (p[2]->y - p[1]->y) * (b.width - p[1]->x)
			/ (p[2]->x - p[1]->x);
		p[0]->x = b.width;
	}
	else if (code & LEFT)
	{
		p[0]->y = p[1]->y + (p[2]->y - p[1]->y) * (b.x - p[1]->x)
			/ (p[2]->x - p[1]->x);
		p[0]->x = b.x;
	}
}

/*
https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
*/
static int	line_clip(uint8_t codes[2], t_point *p1, t_point *p2, t_rect b)
{
	t_point		*pts[3];

	pts[1] = p1;
	pts[2] = p2;
	while (codes[0] | codes[1])
	{
		if (codes[0] & codes[1])
			return (0);
		if (codes[1] <= codes[0])
		{
			pts[0] = p1;
			line_clip_inside(pts, codes[0], b);
			codes[0] = out_code(b, *p1);
		}
		else
		{
			pts[0] = p2;
			line_clip_inside(pts, codes[1], b);
			codes[1] = out_code(b, *p2);
		}
	}
	return (1);
}

void	llx_paint_line(t_llx_paint *paint, t_point p1, t_point p2)
{
	uint32_t	flags;
	t_rect		b;
	uint8_t		codes[2];

	b = paint->bounds;
	b.width--;
	b.height--;
	codes[0] = out_code(b, p1);
	codes[1] = out_code(b, p2);
	if (!line_clip(codes, &p1, &p2, b))
		return ;
	if (p1.x == p2.x || p1.y == p2.y)
	{
		draw_line(paint, p1, p2);
		return ;
	}
	flags = paint->flags;
	if (flags & Paint_Flag_Antialiasing)
		draw_line_aa(paint, p1, p2);
	else
		draw_line(paint, p1, p2);
}
