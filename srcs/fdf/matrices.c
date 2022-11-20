#include "fdf.h"

#define ASPECT_RATIO 16.0f / 9.0f
#define FOV 90.0f
#define NEAR 0.1f
#define FAR	1000.0f

t_mat4x4	fdf_projection_matrix(void)
{
	t_mat4x4	mat;
	float		fov_rad;

	ft_memset(mat.m, 0, sizeof(float) * 16);
	fov_rad	= 1.0f / tanf(FOV * 0.5f / 180.0f * (float)M_PI);
	mat.m[0][0] = ASPECT_RATIO * fov_rad;
	mat.m[1][1] = fov_rad;
	mat.m[2][2] = FAR / (FAR - NEAR);
	mat.m[3][2] = (-FAR * NEAR) / (FAR - NEAR);
	mat.m[2][3] = 1.0f;
	mat.m[3][3] = 0.0f;
	return (mat);
}
