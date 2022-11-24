/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:39 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:41 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_fill(t_llx_paint *paint)
{
	register uint32_t	*ptr;
	register uint32_t	*end;
	register uint32_t	color;

	if (!paint)
		return ;
	ptr = paint->data;
	end = ptr + (size_t)(paint->bounds.height * paint->line_size);
	color = paint->pen.ucolor;
	while (ptr != end)
	{
		*ptr = color;
		ptr++;
	}
}
