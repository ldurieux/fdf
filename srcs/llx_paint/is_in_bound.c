/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_bound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:39 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint_internal.h"
#include "llx_paint.h"

int	is_in_bound(t_llx_paint *paint, int x, int y)
{
	t_rect	b;

	b = paint->bounds;
	return (x >= b.x && x < b.width && y >= b.y && y < b.height);
}
