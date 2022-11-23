/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:31:12 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:31:15 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_3D_H
# define LLX_3D_H

# include <math.h>
# include "libft.h"

typedef struct s_point	t_point;
typedef struct s_size	t_size;

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

typedef struct s_transform_3d
{
	t_vec3	trans;
	t_vec3	rot;
	t_vec3	scale;
}	t_transform_3d;

void		llx_mul_vec3_mat4x4(t_vec3 *out, t_vec3 in, t_mat4x4 *mat);
void		llx_mul_vec3_unique(t_vec3 *i, t_vec3 *o);
void		llx_mul_vec3_number(float f, t_vec3 *o);
void		llx_add_vec3(t_vec3 *i, t_vec3 *o);

t_mat4x4	llx_perspective_projection_matrix(t_size view_size);
t_mat4x4	llx_isometric_projection_matrix(t_size view_size);
t_mat4x4	llx_rotation_matrix(float yaw, float pitch, float roll);

#endif // LLX_3D_H
