#include "llx_paint_internal.h"
#include "llx_paint.h"

int	is_in_bound(t_llx_paint *paint, int x, int y)
{
	t_point	max;

	max.x = paint->bounds.x + paint->bounds.width;
	max.y = paint->bounds.y + paint->bounds.height;
	return (x >= paint->bounds.x && x < max.x
			&& y >= paint->bounds.y && y < max.y);
}
