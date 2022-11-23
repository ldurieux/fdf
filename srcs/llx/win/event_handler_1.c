/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:17 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:18 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"
#include "llx_win_internal.h"

void	llx_on_key_down(int keycode, t_llx_win *ptr)
{
	if (ptr->last_key_idx < MAX_KEY_IDX
		&& !llx_win_is_key_down(ptr, keycode))
	{
		ptr->last_key_idx++;
		ptr->keys[ptr->last_key_idx] = keycode;
	}
	if (ptr->on_key_down)
		ptr->on_key_down(ptr, keycode);
}

void	llx_on_key_up(int keycode, t_llx_win *ptr)
{
	int	key_idx;

	key_idx = llx_win_key_down_idx(ptr, keycode);
	if (key_idx != -1)
	{
		ptr->keys[key_idx] = ptr->keys[ptr->last_key_idx];
		ptr->last_key_idx--;
	}
	if (ptr->on_key_up)
		ptr->on_key_up(ptr, keycode);
}

void	llx_on_mouse_down(int button, int x, int y, t_llx_win *ptr)
{
	if (ptr->on_mouse_down)
		ptr->on_mouse_down(ptr, button, x, y);
}

void	llx_on_mouse_up(int button, int x, int y, t_llx_win *ptr)
{
	if (ptr->on_mouse_up)
		ptr->on_mouse_up(ptr, button, x, y);
}

void	llx_on_mouse_move(int x, int y, t_llx_win *ptr)
{
	if (ptr->on_mouse_move)
		ptr->on_mouse_move(ptr, x, y);
}
