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

void	llx_mul_vec3_mat4x4(t_vec3 *out, t_vec3 in, t_mat4x4 *mat)
{
	float	w;

	out->x = in.x * mat->m[0][0] + in.y * mat->m[1][0]
		+ in.z * mat->m[2][0] + mat->m[3][0];
	out->y = in.x * mat->m[0][1] + in.y * mat->m[1][1]
		+ in.z * mat->m[2][1] + mat->m[3][1];
	out->z = in.x * mat->m[0][2] + in.y * mat->m[1][2]
		+ in.z * mat->m[2][2] + mat->m[3][2];
	w = in.x * mat->m[0][3] + in.y * mat->m[1][3]
		+ in.z * mat->m[2][3] + mat->m[3][3];
	if (w != 0.0f)
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
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
