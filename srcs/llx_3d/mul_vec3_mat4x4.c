/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_vec_mat4x4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:52:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 22:52:08 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_3d.h"

void	llx_mul_vec3_mat4x4(t_mat4x4 *matrix, t_vec3 *vec)
{
	float	w;

	vec->x = vec->x * matrix->m[0][0] + vec->y * matrix->m[1][0] + vec->z * matrix->m[2][0] + matrix->m[3][0];
	vec->y = vec->x * matrix->m[0][1] + vec->y * matrix->m[1][1] + vec->z * matrix->m[2][1] + matrix->m[3][1];
	vec->z = vec->x * matrix->m[0][2] + vec->y * matrix->m[1][2] + vec->z * matrix->m[2][2] + matrix->m[3][2];
	w = vec->x * matrix->m[0][3] + vec->y * matrix->m[1][3] + vec->z * matrix->m[2][3] + matrix->m[3][3];
	if (w != 0.0f)
	{
		vec->x /= w;
		vec->y /= w;
		vec->z /= w;
	}
}

void	llx_mul_vec3_unique(t_vec3 *i, t_vec3 *o)
{
	i->x *= o->x;
	i->y *= o->y;
	i->z *= o->z;
}

void	llx_mul_vec3_number(float f, t_vec3 *o)
{
	o->x *= f;
	o->y *= f;
	o->z *= f;
}
