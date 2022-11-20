#include "llx_win.h"
#include "llx_win_internal.h"
#include "llx.h"

static void	connect_win(t_llx_win *w)
{
	void	*m;

	m = w->mlx_win;
	mlx_hook(m, LlxEvt_KeyPress, LlxMsk_KeyPress, llx_on_key_down, w);
	mlx_hook(m, LlxEvt_KeyRelease, LlxMsk_KeyRelease, llx_on_key_up, w);
	mlx_hook(m, LlxEvt_ButtonPress, LlxMsk_ButtonPress, llx_on_mouse_down, w);
	mlx_hook(m, LlxEvt_ButtonRelease, LlxMsk_ButtonRelease,
		llx_on_mouse_up, w);
	mlx_hook(m, LlxEvt_MotionNotify, LlxMsk_NoEvent, llx_on_mouse_move, w);
	mlx_hook(m, LlxEvt_EnterNotify, LlxMsk_EnterWindow, llx_on_enter, w);
	mlx_hook(m, LlxEvt_LeaveNotify, LlxMsk_LeaveWindow, llx_on_leave, w);
	mlx_hook(m, LlxEvt_DestroyNotify, LlxMsk_NoEvent, llx_on_close, w);
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
	win->llx = llx;
	win->id = llx->last_win_id;
	win->width = width;
	win->height = height;
	win->cache = mlx_new_image(llx->mlx, width, height);
	win->mlx_win = mlx_new_window(llx->mlx, width, height, title);
	if (!win->mlx_win || !win->cache)
		return (llx_win_delete(win), NULL);
	llx->last_win_id++;
	llx->windows[win->id] = win;
	connect_win(win);
	return (win);
}
