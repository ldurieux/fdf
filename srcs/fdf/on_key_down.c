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

static void	preset_keys(t_fdf *fdf, int key)
{
	if (key == LlxKey_0)
		fdf_load_preset(fdf, 0);
	if (key == LlxKey_1)
		fdf_load_preset(fdf, 1);
	if (key == LlxKey_2)
		fdf_load_preset(fdf, 2);
	if (key == LlxKey_3)
		fdf_load_preset(fdf, 3);
	if (key == LlxKey_4)
		fdf_load_preset(fdf, 4);
	if (key == LlxKey_5)
		fdf_load_preset(fdf, 5);
	if (key == LlxKey_6)
		fdf_load_preset(fdf, 6);
	if (key == LlxKey_7)
		ft_printf("scale (%d, %d, %d)\n", (int)(fdf->scale.x * 1000),
			(int)(fdf->scale.y * 1000), (int)(fdf->scale.z * 1000));
	if (key == LlxKey_8)
		ft_printf("translate (%d, %d, %d)\n", (int)(fdf->trans.x * 1000),
			(int)(fdf->trans.y * 1000), (int)(fdf->trans.z * 1000));
	if (key == LlxKey_9)
		ft_printf("rotate (%d, %d, %d)\n", (int)(fdf->rot.x * 1000),
			(int)(fdf->rot.y * 1000), (int)(fdf->rot.z * 1000));
}

void	fdf_on_key_down(t_llx_win *win, int key)
{
	t_fdf	*fdf;

	fdf = win->llx->data;
	preset_keys(fdf, key);
	if (key == LlxKey_P)
		fdf_switch_projection(fdf);
	else if (key == LlxKey_M)
		fdf_switch_scale_mode(fdf);
	else if (key == LlxKey_O)
		fdf_switch_draw_mode(fdf);
	else if (key == LlxKey_C)
		fdf_switch_color_mode(fdf);
}

void	fdf_while_key_down(t_llx_win *win, t_fdf *fdf)
{
	t_vec3	*rot;
	t_vec3	*trans;

	rot = &fdf->rot;
	trans = &fdf->trans;
	rot->x -= 0.01f * (float)llx_win_is_key_down(win, LlxKey_W);
	rot->x += 0.01f * (float)llx_win_is_key_down(win, LlxKey_S);
	rot->y += 0.01f * (float)llx_win_is_key_down(win, LlxKey_A);
	rot->y -= 0.01f * (float)llx_win_is_key_down(win, LlxKey_D);
	rot->z += 0.01f * (float)llx_win_is_key_down(win, LlxKey_E);
	rot->z -= 0.01f * (float)llx_win_is_key_down(win, LlxKey_Q);
	trans->x += 0.01f * (float)llx_win_is_key_down(win, LlxKey_Right);
	trans->x -= 0.01f * (float)llx_win_is_key_down(win, LlxKey_Left);
	trans->y -= 0.01f * (float)llx_win_is_key_down(win, LlxKey_Up);
	trans->y += 0.01f * (float)llx_win_is_key_down(win, LlxKey_Down);
	if (llx_win_is_key_down(win, LlxKey_Plus))
		fdf_scale(fdf, 1.01f);
	if (llx_win_is_key_down(win, LlxKey_Minus))
		fdf_scale(fdf, 0.99f);
}
