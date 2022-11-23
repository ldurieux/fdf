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

void	fdf_on_key_down(t_llx_win *win, int key)
{
	t_fdf	*fdf;

	fdf = win->llx->data;
	if (key == LlxKey_P)
		fdf_switch_projection(fdf);
	else if (key == LlxKey_M)
		fdf_switch_scale_mode(fdf);
}

void	fdf_while_key_down(t_llx_win *win, t_fdf *fdf)
{
	t_vec3	*rot;
	t_vec3	*trans;

	rot = &fdf->rot;
	trans = &fdf->trans;
	rot->x -= 0.002f * (float)llx_win_is_key_down(win, LlxKey_Z);
	rot->x += 0.002f * (float)llx_win_is_key_down(win, LlxKey_S);
	rot->y += 0.002f * (float)llx_win_is_key_down(win, LlxKey_Q);
	rot->y -= 0.002f * (float)llx_win_is_key_down(win, LlxKey_D);
	rot->z += 0.002f * (float)llx_win_is_key_down(win, LlxKey_E);
	rot->z -= 0.002f * (float)llx_win_is_key_down(win, LlxKey_A);
	trans->x += 0.002f * (float)llx_win_is_key_down(win, LlxKey_Right);
	trans->x -= 0.002f * (float)llx_win_is_key_down(win, LlxKey_Left);
	trans->y -= 0.002f * (float)llx_win_is_key_down(win, LlxKey_Up);
	trans->y += 0.002f * (float)llx_win_is_key_down(win, LlxKey_Down);
	if (llx_win_is_key_down(win, LlxKey_Plus))
		fdf_scale(fdf, 1.002f);
	if (llx_win_is_key_down(win, LlxKey_Minus))
		fdf_scale(fdf, 0.998f);
}
