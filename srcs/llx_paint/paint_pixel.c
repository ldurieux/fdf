#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_pixel(t_llx_paint *paint, t_point p)
{
	uint32_t	*ptr;
	char		*data;
	int			size_line;
	int			bpp;

	if (!paint)
		return ;
	if (!is_in_bound(paint, p.x, p.y))
		return ;
	data = paint->img->data;
	size_line = paint->img->size_line;
	bpp = paint->img->bpp;
	ptr = (uint32_t*)(data + (p.y * size_line + p.x * (bpp / BITS_PER_BYTE)));
	*ptr = paint->pen.ucolor;
}
