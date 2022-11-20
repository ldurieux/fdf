/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:52:24 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 22:52:27 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void		fdf_add_vec3(t_vec3 *i, t_vec3 *o);

t_mat4x4	fdf_projection_matrix(void);
t_mat4x4	fdf_isometric_projection_matrix(void);
t_mat4x4	fdf_rotation_matrix(float yaw, float pitch, float roll);

#endif // FDF_H
