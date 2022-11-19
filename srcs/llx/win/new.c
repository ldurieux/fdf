#include "llx_win.h"
#include "llx_win_internal.h"
#include "llx.h"

static void	connect_win(t_llx_win *win)
{
	mlx_win_list_t	*mlx_win;

	mlx_win = win->mlx_win;
	mlx_hook(mlx_win, 2, 0x1, llx_on_key_down, win);
	mlx_hook(mlx_win, 3, 0x2, llx_on_key_up, win);
	mlx_hook(mlx_win, 4, 0x4, llx_on_mouse_down, win);
	mlx_hook(mlx_win, 5, 0x8, llx_on_mouse_up, win);
	mlx_hook(mlx_win, 6, 0x0, llx_on_mouse_move, win);
	mlx_hook(mlx_win, 7, 0x10, llx_on_enter, win);
	mlx_hook(mlx_win, 8, 0x20, llx_on_leave, win);
	mlx_hook(mlx_win, 17, 0x0, llx_on_close, win);
}

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title)
{
	t_llx_win	*win;

	if (!llx || width < 10 || height < 10 || !title
		|| llx->last_win_id >= LLX_MAX_WIN)
		return (NULL);
	win = malloc(sizeof(t_llx_win));
	if (!win)
		return (NULL);
	win->llx = llx;
	win->id = llx->last_win_id;
	win->width = width;
	win->height = height;
	win->cache = NULL;
	win->mlx_win = mlx_new_window(llx->mlx, width, height, title);
	if (!win->mlx_win)
		return (NULL);
	llx->last_win_id++;
	llx->windows[win->id] = win;
	connect_win(win);
	return (win);
}
