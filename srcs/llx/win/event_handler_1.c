#include "llx_win_internal.h"

void	llx_on_key_down(int keycode, t_llx_win *ptr)
{
	ft_printf("on key down %d\n", keycode);
}

void	llx_on_key_up(int keycode, t_llx_win *ptr)
{
	ft_printf("on key up %d\n", keycode);
}

void	llx_on_mouse_down(int button, int x, int y, t_llx_win *ptr)
{
	ft_printf("on mouse down %d (%d, %d)\n", button, x, y);
}

void	llx_on_mouse_up(int button, int x, int y, t_llx_win *ptr)
{
	ft_printf("on mouse up %d (%d, %d)\n", button, x, y);
}

void	llx_on_mouse_move(int x, int y, t_llx_win *ptr)
{

}
