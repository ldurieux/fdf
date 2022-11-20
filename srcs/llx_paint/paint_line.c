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

void	llx_paint_line(t_llx_paint *paint, t_point p1, t_point p2)
{
	uint32_t	flags;

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