/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_aa_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:31 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:32 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint_internal.h"
#include "llx_paint.h"

void	plot(t_llx_paint *paint, int32_t x, int32_t y, float brightness)
{
	t_color	color;

	if (!is_in_bound(paint, x, y))
		return ;
	color = paint->pen;
	color.rgba.a = (uint8_t)((float)color.rgba.a * brightness);
	blend_pixel(paint, x, y, color.ucolor);
}
