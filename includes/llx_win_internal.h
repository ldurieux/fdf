#ifndef LLX_WIN_INTERNAL_H
# define LLX_WIN_INTERNAL_H

# include "ft_printf.h"

typedef struct s_llx_win	t_llx_win;

void	llx_on_key_down(int keycode, t_llx_win *ptr);
void	llx_on_key_up(int keycode, t_llx_win *ptr);
void	llx_on_mouse_down(int button, int x, int y, t_llx_win *ptr);
void	llx_on_mouse_up(int button, int x, int y, t_llx_win *ptr);
void	llx_on_mouse_move(int x, int y, t_llx_win *ptr);
void	llx_on_enter(t_llx_win *ptr);
void	llx_on_leave(t_llx_win *ptr);
void	llx_on_close(t_llx_win *ptr);

#endif // LLX_WIN_INTERNAL_H
