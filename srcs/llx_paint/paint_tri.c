/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:45 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:50 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_tri(t_llx_paint *paint, t_point p1, t_point p2, t_point p3)
{
	if (paint->brush.rgba.a != UINT8_MAX)
	{
		if (p2.y < p1.y)
			ft_swap(&p1, &p2, sizeof(t_point));
		if (p3.y < p1.y)
			ft_swap(&p1, &p3, sizeof(t_point));
		if (p3.y < p2.y)
			ft_swap(&p2, &p3, sizeof(t_point));
		draw_tri(paint, p1, p2, p3);
	}
	if (paint->pen.rgba.a != 0)
	{
		llx_paint_line(paint, p1, p2);
		llx_paint_line(paint, p2, p3);
		llx_paint_line(paint, p3, p1);
	}
}
