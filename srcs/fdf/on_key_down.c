/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:30:00 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/22 16:30:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_or_translate(t_fdf *fdf, int key)
{
	t_vec3	*rot;
	t_vec3	*trans;

	rot = &fdf->rot;
	trans = &fdf->trans;
	if (key == LlxKey_Z)
		rot->x -= 0.1f;
	else if (key == LlxKey_S)
		rot->x += 0.1f;
	else if (key == LlxKey_Q)
		rot->y += 0.1f;
	else if (key == LlxKey_D)
		rot->y -= 0.1f;
	else if (key == LlxKey_E)
		rot->z += 0.1f;
	else if (key == LlxKey_A)
		rot->z -= 0.1f;
	else if (key == LlxKey_Right)
		trans->x += 0.1f;
	else if (key == LlxKey_Left)
		trans->x -= 0.1f;
	else if (key == LlxKey_Up)
		trans->y -= 0.1f;
	else if (key == LlxKey_Down)
		trans->y += 0.1f;
}

void	fdf_on_key_down(t_llx_win *win, int key)
{
	t_fdf	*fdf;

	fdf = win->llx->data;
	rotate_or_translate(fdf, key);
	if (key == LlxKey_P)
		fdf_switch_projection(fdf);
	else if (key == LlxKey_M)
		fdf_switch_scale_mode(fdf);
	else if (key == LlxKey_Plus)
		fdf_scale(fdf, 1.05f);
	else if (key == LlxKey_Minus)
		fdf_scale(fdf, 0.95f);
	else
		ft_printf("%d\n", key);
}
