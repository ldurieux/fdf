#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_fill(t_llx_paint *paint)
{
	char		*ptr;
	char		*end;
	uint32_t	*tmp;
	uint32_t	increment;
	uint32_t	color;

	if (!paint)
		return ;
	ptr = paint->img->data;
	increment = paint->img->bpp / BITS_PER_BYTE;
	end = ptr + (ptrdiff_t)(paint->img->height * paint->img->width * increment);
	color = paint->pen.ucolor;
	while (ptr != end)
	{
		tmp = (int*)ptr;
		*tmp = color;
		ptr += increment;
	}
}
