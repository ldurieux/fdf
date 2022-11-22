/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:31:31 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:31:33 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx.h"
#include "llx_paint.h"
#include "llx_3d.h"
#include "fdf.h"

#include "ft_printf.h"

static int	start_llx(t_fdf *fdf)
{
	t_llx		*llx;
	t_llx_win	*win;

	llx = llx_init();
	if (!llx)
		return (1);
	llx->data = fdf;
	win = llx_win_new(llx, fdf->win_size.width, fdf->win_size.height, "test");
	win->on_key_down = fdf_on_key_down;
	llx->on_loop = fdf_on_loop;
	return (llx_exec(llx));
}

int	main(void)
{
	t_fdf	fdf;
	float	ratio;
	char	*path = "/mnt/data/home/loudur/project/42/llx2/test_maps/elem2.fdf";

	if (!fdf_read_file(path, &fdf.orig_points, &fdf.colors, &fdf.map_size))
		return (1);
	ratio = fdf.map_size.width;
	if (ratio < fdf.map_size.height)
		ratio = fdf.map_size.height;
	fdf.points = NULL;
	fdf.win_size = (t_size){480, 480};
	fdf.rot = (t_vec3){M_PI / 3, 0.5f, M_PI / 5};
	fdf.trans = (t_vec3){0.0f, 0.0f, 1.0f};
	fdf.scale = (t_vec3){1 / ratio, 1 / ratio, 1 / ratio};
	fdf.proj_matrix = llx_isometric_projection_matrix();
	fdf.flags = 0;
	fdf_scale_points(&fdf);
	return (start_llx(&fdf));
}
