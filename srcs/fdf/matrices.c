#include "fdf.h"

#define ASPECT_RATIO 16.0f / 9.0f
#define FOV 90.0f
#define NEAR 0.1f
#define FAR	1000.0f
#define WIDTH 1
#define HEIGHT 1

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

t_mat4x4	fdf_isometric_projection_matrix(void)
{
	t_mat4x4	mat;

	ft_memset(mat.m, 0, sizeof(float) * 16);
	mat.m[0][0] = 2 / WIDTH;
	mat.m[1][1] = 2 / HEIGHT;
	mat.m[2][2] = -2 / (FAR - NEAR);
	mat.m[3][2] = - (FAR + NEAR) / (FAR - NEAR);
	mat.m[3][3] = 1;
	return (mat);
}

t_mat4x4	fdf_rotation_matrix(float yaw, float pitch, float roll)
{
	t_mat4x4	mat;

	ft_memset(mat.m, 0, sizeof(float) * 16);
	mat.m[0][0] = cosf(yaw) * cosf(pitch);
	mat.m[0][1] = sinf(yaw) * cosf(pitch);
	mat.m[0][2] = -sinf(pitch);

	mat.m[1][0] = cosf(yaw) * sinf(pitch) * sinf(roll) - sinf(yaw) * cosf(roll);
	mat.m[1][1] = sinf(yaw) * sinf(pitch) * sinf(roll) + cosf(yaw) * cosf(roll);
	mat.m[1][2] = cosf(pitch) * sinf(roll);

	mat.m[2][0] = cosf(yaw) * sinf(pitch) * cosf(roll) + sinf(yaw) * sinf(roll);
	mat.m[2][1] = sinf(yaw) * sinf(pitch) * cosf(roll) - cosf(yaw) * sinf(roll);
	mat.m[2][2] = cosf(pitch) * cosf(roll);
	return (mat);
}
