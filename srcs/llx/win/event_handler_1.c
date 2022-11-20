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
	if (ptr->on_key_down)
		ptr->on_key_down(ptr, keycode);
}

void	llx_on_key_up(int keycode, t_llx_win *ptr)
{
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
