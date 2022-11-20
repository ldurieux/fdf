/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_paint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:18:50 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:18:52 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_PAINT_H
# define LLX_PAINT_H

# include "libft.h"
# include "llx.h"
# include <stddef.h>

# define BITS_PER_BYTE 8

enum e_color : uint32_t
{
	Llx_Transparent	= 0xff000000,
	Llx_White		= 0x00ffffff,
	Llx_Black		= 0x00000000,
	Llx_Red			= 0x00ff0000,
	Llx_Green		= 0x0000ff00,
	Llx_Blue		= 0x000000ff,
	Llx_Yellow		= Llx_Red | Llx_Green,
	Llx_Magenta		= Llx_Red | Llx_Blue,
	Llx_Cyan		= Llx_Green | Llx_Blue,
};

enum e_paint_flag
{
	Paint_Flag_Antialiasing	= 0x1,
};

typedef struct s_rgba
{
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
	uint8_t	a;
}	t_rgba;

typedef union u_color
{
	int32_t		color;
	uint32_t	ucolor;
	t_rgba		rgba;
}	t_color;

typedef struct s_llx_paint
{
	void		*img;
	t_color		brush;
	t_color		pen;
	t_rect		bounds;
	uint32_t	flags;
}	t_llx_paint;

void	llx_paint_fill(t_llx_paint *paint);
void	llx_paint_pixel(t_llx_paint *paint, t_point p);
void	llx_paint_line(t_llx_paint *paint, t_point p1, t_point p2);
void	llx_paint_tri(t_llx_paint *paint, t_point p1, t_point p2, t_point p3);

#endif // LLX_PAINT_H
