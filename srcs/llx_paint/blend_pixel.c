#include "llx_paint_internal.h"
#include "llx_paint.h"

void	blend_pixel(t_llx_paint *paint, int x, int y, uint32_t color)
{
	t_rgba	*ptr;
	t_rgba	wanted;
	t_rgba	origin;
	float	blend;

	wanted = *(t_rgba*)&color;
	ptr = (t_rgba*)(paint->img->data + (y * paint->img->size_line
			+ x * (paint->img->bpp / BITS_PER_BYTE)));
	if (wanted.a == UINT8_MAX)
		*ptr = wanted;
	else
	{
		origin = *ptr;
		blend = (float)wanted.a / UINT8_MAX;
		origin.r += (int)((float)(wanted.r - origin.r) * blend);
		origin.g += (int)((float)(wanted.g - origin.g) * blend);
		origin.b += (int)((float)(wanted.b - origin.b) * blend);
		*ptr = origin;
	}
}
