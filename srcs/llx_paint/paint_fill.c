#include "llx_paint.h"
#include "llx_paint_internal.h"

void	llx_paint_fill(t_llx_paint *paint)
{
	uint32_t	*ptr;
	uint32_t	*end;
	uint32_t	color;
	t_img_data	data;

	if (!paint)
		return ;
	ptr = mlx_get_data_addr(paint->img, &data.pixel_bits,
		&data.line_bytes, &data.endian);
	end = ptr + paint->bounds.height * data.line_bytes / 4;
	color = paint->pen.ucolor;
	while (ptr != end)
	{
		*ptr = color;
		ptr++;
	}
}
