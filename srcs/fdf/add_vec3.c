#include "fdf.h"

void	fdf_add_vec3(t_vec3 *i, t_vec3 *o)
{
	o->x += i->x;
	o->y += i->y;
	o->z += i->z;
}
