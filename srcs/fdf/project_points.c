/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:32:16 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/23 18:32:19 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	matrix_mult(register t_vec3 *res, t_vec3 *pts, size_t count,
						t_mat4x4 *mat_ref)
{
	register t_vec3		*end;
	register t_vec3		pt;
	register t_mat4x4	mat;
	register float		w;

	mat = *mat_ref;
	end = res + count - 1;
	while (++res != end)
	{
		pt = *pts++;
		res->x = pt.x * mat.m[0][0] + pt.y * mat.m[1][0]
			+ pt.z * mat.m[2][0] + mat.m[3][0];
		res->y = pt.x * mat.m[0][1] + pt.y * mat.m[1][1]
			+ pt.z * mat.m[2][1] + mat.m[3][1];
		res->z = pt.x * mat.m[0][2] + pt.y * mat.m[1][2]
			+ pt.z * mat.m[2][2] + mat.m[3][2];
		w = pt.x * mat.m[0][3] + pt.y * mat.m[1][3]
			+ pt.z * mat.m[2][3] + mat.m[3][3];
		if (w != 0.0f)
		{
			res->x /= w;
			res->y /= w;
			res->z /= w;
		}
	}
}

static void	vec3_add(register t_vec3 *res, t_vec3 *add, size_t count)
{
	register t_vec3	*end_ptr;
	register t_vec3	to_add;

	to_add = *add;
	end_ptr = res + count;
	while (res != end_ptr)
	{
		res->x += to_add.x;
		res->y += to_add.y;
		res->z += to_add.z;
		res++;
	}
}

static void	to_point(register t_point *res, register t_vec3 *vec,
					size_t count, t_size *mul)
{
	register t_point	*end_ptr;
	register float		to_mul_x;
	register float		to_mul_y;

	to_mul_x = (float)mul->width;
	to_mul_y = (float)mul->height;
	end_ptr = res + count;
	while (res != end_ptr)
	{
		res->x = (int)((vec->x + 1.0f) * to_mul_x);
		res->y = (int)((vec->y + 1.0f) * to_mul_y);
		vec++;
		res++;
	}
}

int	fdf_project_points(t_fdf *fdf, t_point **points)
{
	t_vec3		*projected;
	size_t		count;
	t_mat4x4	mat_rot;
	t_size		half_win_size;

	half_win_size = fdf->win_size;
	half_win_size.width /= 2;
	half_win_size.height /= 2;
	mat_rot = llx_rotation_matrix(fdf->rot.z, fdf->rot.y, fdf->rot.x);
	count = (size_t)fdf->map_size.width * (size_t)fdf->map_size.height;
	projected = malloc(sizeof(t_vec3) * count);
	*points = malloc(sizeof(t_point) * count);
	if (!*points || !projected)
		return (free(points), free(projected), 0);
	matrix_mult(projected, fdf->points, count, &mat_rot);
	vec3_add(projected, &fdf->trans, count);
	matrix_mult(projected, projected, count, &fdf->proj_matrix);
	to_point(*points, projected, count, &half_win_size);
	return (free(projected), 1);
}
