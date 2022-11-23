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

# include <fcntl.h>
# include "libft.h"
# include "ft_frwlist.h"
# include "llx_paint.h"
# include "llx_3d.h"

enum e_fdf_flags
{
	Fdf_perspective_projection = 0x1,
	Fdf_scale_section = 0x2,
};

typedef struct s_fdf
{
	t_vec3		*orig_points;
	t_vec3		*points;
	t_color		*colors;
	t_size		map_size;
	t_size		win_size;
	t_vec3		rot;
	t_vec3		trans;
	t_vec3		scale;
	t_mat4x4	proj_matrix;
	uint32_t	flags;
}	t_fdf;

int		fdf_on_loop(t_llx *llx);
void	fdf_on_key_down(t_llx_win *win, int key);
void	fdf_while_key_down(t_llx_win *win, t_fdf *fdf);

int		fdf_read_file(char *path, t_vec3 **points, t_color **colors,
			t_size *size);
int		fdf_parse_data(char *data, t_vec3 **points, t_color **colors,
			t_size *size);

void	fdf_switch_projection(t_fdf *fdf);
void	fdf_switch_scale_mode(t_fdf *fdf);

void	fdf_scale(t_fdf *fdf, float value);
void	fdf_scale_points(t_fdf *fdf);

#endif // FDF_H
