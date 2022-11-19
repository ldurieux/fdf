#ifndef LLX_PAINT_INTERNAL_H
# define LLX_PAINT_INTERNAL_H

# include "libft.h"
# include "llx.h"
# include <stdint.h>

typedef struct s_llx_paint t_llx_paint;

int		is_in_bound(t_llx_paint *paint, int x, int y);

void	blend_pixel(t_llx_paint *paint, int x, int y, uint32_t color);

void	draw_line(t_llx_paint *paint, t_point p1, t_point p2);
void	draw_line_aa(t_llx_paint *paint, t_point p1, t_point p2);
void	draw_tri(t_llx_paint *paint, t_point p1, t_point p2, t_point p3);

#endif // LLX_PAINT_INTERNAL_H
