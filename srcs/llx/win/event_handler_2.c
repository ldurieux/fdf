#include "llx_win_internal.h"
#include "llx_win.h"

void	llx_on_enter(t_llx_win *ptr)
{

}

void	llx_on_leave(t_llx_win *ptr)
{

}

void	llx_on_close(t_llx_win *ptr)
{
	llx_win_delete(ptr);
}
