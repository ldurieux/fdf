#include "llx_win_internal.h"
#include "llx_win.h"

void	llx_on_enter(t_llx_win *ptr)
{
	ft_printf("on enter\n");
}

void	llx_on_leave(t_llx_win *ptr)
{
	ft_printf("on leave\n");
}

void	llx_on_close(t_llx_win *ptr)
{
	llx_win_delete(ptr);
}
