/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:57 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:29:58 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_scale_points(t_fdf *fdf)
{
	size_t	idx;
	size_t	count;
	t_vec3	scale;
	t_vec3	*points;
	t_vec3	*orig_points;

	orig_points = fdf->orig_points;
	scale = fdf->scale;
	idx = (size_t)-1;
	count = (size_t)fdf->map_size.width * (size_t)fdf->map_size.height;
	points = malloc(sizeof(t_vec3) * count);
	if (!points)
		return ;
	while (++idx < count)
	{
		points[idx].x = orig_points[idx].x * scale.x;
		points[idx].y = orig_points[idx].y * scale.y;
		points[idx].z = orig_points[idx].z * scale.z;
	}
	free(fdf->points);
	fdf->points = points;
}

void	fdf_scale(t_fdf *fdf, float value)
{
	if (fdf->flags & Fdf_scale_section)
	{
		fdf->scale.x *= value;
		fdf->scale.z *= value;
	}
	fdf->scale.y *= value;
	fdf_scale_points(fdf);
}

static float	ft_absf(float val)
{
	if (val < 0)
		return (-val);
	return (val);
}

static float	find_highest(t_vec3 *pts, t_size map_size)
{
	size_t	idx;
	size_t	end;
	float	res;

	idx = (size_t)-1;
	end = (size_t)map_size.width * (size_t)map_size.height;
	res = 0.0f;
	while (++idx < end)
		if (ft_absf(pts[idx].y) > res)
			res = ft_absf(pts[idx].y);
	return (res);
}

void	fdf_scale_to_fit(t_fdf *fdf)
{
	float	section_scale;
	float	highest;

	section_scale = (float)fdf->map_size.width;
	highest = find_highest(fdf->orig_points, fdf->map_size);
	if (highest < 1.0f)
		highest = 1.0f;
	fdf->scale = (t_vec3){1 / section_scale, 1 / highest, 1 / section_scale};
}
