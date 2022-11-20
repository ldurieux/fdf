/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:23 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:25 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint_internal.h"
#include "llx_paint.h"

void	blend_pixel(t_llx_paint *paint, int x, int y, uint32_t color)
{
	t_rgba		*ptr;
	t_img_data	data;
	t_rgba		wanted;
	t_rgba		origin;
	float		blend;

	wanted = *(t_rgba *)&color;
	ptr = (t_rgba *)mlx_get_data_addr(paint->img, &data.pixel_bits,
			&data.line_bytes, &data.endian);
	ptr += y * data.line_bytes / 4 + x;
	if (wanted.a == 0)
		*ptr = wanted;
	else
	{
		origin = *ptr;
		blend = (float)(UINT8_MAX - wanted.a) / UINT8_MAX;
		origin.r += (int)((float)(wanted.r - origin.r) *blend);
		origin.g += (int)((float)(wanted.g - origin.g) *blend);
		origin.b += (int)((float)(wanted.b - origin.b) *blend);
		*ptr = origin;
	}
}
