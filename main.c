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
	char	*path = "/mnt/data/home/loudur/project/42/llx2/test_maps/elem-fract.fdf";

	if (!fdf_read_file(path, &fdf.orig_points, &fdf.colors, &fdf.map_size))
		return (1);
	fdf.points = NULL;
	fdf.win_size = (t_size){480, 480};
	fdf.trans = (t_vec3){0.0f, 0.0f, 1.0f};
	fdf.proj_matrix = llx_isometric_projection_matrix();
	fdf.flags = 0;
	fdf_load_preset(&fdf, 1);
	fdf_scale_to_fit(&fdf);
	fdf_scale_points(&fdf);
	return (start_llx(&fdf));
}
