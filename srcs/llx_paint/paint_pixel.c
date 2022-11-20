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
	uint32_t	*ptr;
	t_img_data	data;

	if (!paint)
		return ;
	if (!is_in_bound(paint, p.x, p.y))
		return ;
	ptr = (uint32_t *)mlx_get_data_addr(paint->img, &data.pixel_bits,
			&data.line_bytes, &data.endian);
	ptr[p.y * data.line_bytes / 4 + p.x] = paint->pen.ucolor;
}
