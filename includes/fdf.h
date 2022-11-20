#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft.h"

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_mat4x4
{
	float	m[4][4];
}	t_mat4x4;

void		fdf_mul_vec_mat4x4(t_vec3 *i, t_vec3 *o, t_mat4x4 *m);

t_mat4x4	fdf_projection_matrix(void);

#endif // FDF_H
