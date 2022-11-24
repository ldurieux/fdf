/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:43:19 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/24 08:43:21 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_init(t_llx_paint *paint, t_llx_win *win)
{
	t_img_data	data;

	if (!paint || !win)
		return ;
	paint->data = (uint32_t *)mlx_get_data_addr(win->cache, &data.pixel_bits,
			&data.line_bytes, &data.endian);
	paint->line_size = data.line_bytes / 4;
	paint->brush.ucolor = Llx_Transparent;
	paint->pen.ucolor = Llx_Black;
	paint->gradient.ucolor = Llx_White;
	paint->bounds = (t_rect){0, 0, win->width, win->height};
	paint->flags = 0;
}
