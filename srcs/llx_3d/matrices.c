/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:52:03 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 22:52:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_3d.h"
#include "llx.h"

#define FOV 90.0f
#define NEAR 0.1f
#define FAR	1000.0f
#define WIDTH 1
#define HEIGHT 1

t_mat4x4	llx_perspective_projection_matrix(t_size view_size)
{
	t_mat4x4	mat;
	float		fov_rad;
	float		aspect_ratio;

	aspect_ratio = (float)view_size.height / (float)view_size.width;
	fov_rad = 1.0f / tanf(FOV * 0.5f / 180.0f * (float)M_PI);
	ft_memset(mat.m, 0, sizeof(float) * 16);
	mat.m[0][0] = aspect_ratio * fov_rad;
	mat.m[1][1] = fov_rad;
	mat.m[2][2] = FAR / (FAR - NEAR);
	mat.m[3][2] = (-FAR * NEAR) / (FAR - NEAR);
	mat.m[2][3] = 1.0f;
	mat.m[3][3] = 0.0f;
	return (mat);
}

t_mat4x4	llx_isometric_projection_matrix(t_size view_size)
{
	t_mat4x4	mat;
	float		fov_rad;
	float		aspect_ratio;

	aspect_ratio = (float)view_size.height / (float)view_size.width;
	fov_rad = 1.0f / tanf(FOV * 0.5f / 180.0f * (float)M_PI);
	ft_memset(mat.m, 0, sizeof(float) * 16);
	mat.m[0][0] = aspect_ratio * fov_rad;
	mat.m[1][1] = fov_rad;
	mat.m[2][2] = (FAR - NEAR) / 2;
	mat.m[3][2] = - (FAR + NEAR) / 2;
	mat.m[3][3] = 1;
	return (mat);
}

t_mat4x4	llx_rotation_matrix(float yaw, float pitch, float roll)
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
