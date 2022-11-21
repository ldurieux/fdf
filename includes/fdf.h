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

typedef struct s_fdf
{
	t_vec3		*points;
	t_color		*colors;
	t_size		map_size;
	t_size		win_size;
	t_vec3		rot;
	t_vec3		trans;
	t_mat4x4	proj_matrix;
}	t_fdf;

int	fdf_read_file(char *path, t_vec3 **points, t_color **colors,
			t_size *size);

int	parse_data(char *data, t_vec3 **points, t_color **colors, t_size *size);

#endif // FDF_H
