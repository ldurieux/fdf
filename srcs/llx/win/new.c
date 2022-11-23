/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:21 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:22 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"
#include "llx_win_internal.h"
#include "llx.h"

static void	connect_win(t_llx_win *w)
{
	void	*m;

	m = w->mlx_win;
	mlx_hook(m, LlxEvt_KeyPress, LlxMsk_KeyPress,
		(void *) llx_on_key_down, w);
	mlx_hook(m, LlxEvt_KeyRelease, LlxMsk_KeyRelease,
		(void *) llx_on_key_up, w);
	mlx_hook(m, LlxEvt_ButtonPress, LlxMsk_ButtonPress,
		(void *) llx_on_mouse_down, w);
	mlx_hook(m, LlxEvt_ButtonRelease, LlxMsk_ButtonRelease,
		(void *) llx_on_mouse_up, w);
	mlx_hook(m, LlxEvt_MotionNotify, LlxMsk_NoEvent,
		(void *) llx_on_mouse_move, w);
	mlx_hook(m, LlxEvt_EnterNotify, LlxMsk_EnterWindow,
		(void *) llx_on_enter, w);
	mlx_hook(m, LlxEvt_LeaveNotify, LlxMsk_LeaveWindow,
		(void *) llx_on_leave, w);
	mlx_hook(m, LlxEvt_DestroyNotify, LlxMsk_NoEvent,
		(void *) llx_on_close, w);
}

#define MIN_WIDTH 10
#define MIN_HEIGHT 10

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title)
{
	t_llx_win	*win;

	if (!llx || width < MIN_WIDTH || height < MIN_HEIGHT || !title
		|| llx->last_win_id >= LLX_MAX_WIN)
		return (NULL);
	win = malloc(sizeof(t_llx_win));
	if (!win)
		return (NULL);
	ft_memset(win, 0, sizeof(t_llx_win));
	win->llx = llx;
	win->id = llx->last_win_id;
	win->width = width;
	win->height = height;
	win->last_key_idx = -1;
	win->cache = mlx_new_image(llx->mlx, width, height);
	win->mlx_win = mlx_new_window(llx->mlx, width, height, title);
	if (!win->mlx_win || !win->cache)
		return (llx_win_delete(win), NULL);
	llx->last_win_id++;
	llx->windows[win->id] = win;
	connect_win(win);
	return (win);
}
