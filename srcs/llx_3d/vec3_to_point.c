#include "llx_3d.h"
#include "llx.h"

t_point	llx_vec3_to_point(t_vec3 *vec, t_size half_view_size)
{
	t_point	res;

	res.x = (int)((vec->x + 1.0f) * half_view_size.width);
	res.y = (int)((vec->y + 1.0f) * half_view_size.height);
	return (res);
}
