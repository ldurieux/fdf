/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_preset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:32:19 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/23 18:32:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_load_preset(t_fdf *fdf, int preset)
{
	if (preset == 0)
		fdf->rot = (t_vec3){0, 0, 0};
	else if (preset == 1)
		fdf->rot = (t_vec3){-M_PI / 4 * 3, -0.5f, -0.5f};
	else if (preset == 2)
		fdf->rot = (t_vec3){-M_PI / 2, 0.0f, 0.0f};
	else
		ft_printf("no preset %d\n", preset);
}
