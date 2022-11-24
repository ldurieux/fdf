/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:43 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:45 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_pixel(t_llx_paint *paint, t_point p)
{
	if (!paint)
		return ;
	if (!is_in_bound(paint, p.x, p.y))
		return ;
	paint->data[p.y * paint->line_size + p.x] = paint->pen.ucolor;
}
