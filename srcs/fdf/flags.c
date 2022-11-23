/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:30:02 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:30:03 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_switch_projection(t_fdf *fdf)
{
	fdf->flags ^= Fdf_perspective_projection;
	if (fdf->flags & Fdf_perspective_projection)
		fdf->proj_matrix = llx_perspective_projection_matrix(fdf->win_size);
	else
		fdf->proj_matrix = llx_isometric_projection_matrix();
}

void	fdf_switch_scale_mode(t_fdf *fdf)
{
	fdf->flags ^= Fdf_scale_section;
}

void	fdf_switch_draw_mode(t_fdf *fdf)
{
	fdf->flags ^= Fdf_points_only;
}
