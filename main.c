#include "llx.h"

static int test = 0;

int on_loop(t_llx *llx)
{
	++test;
	if (test == -1)
		llx_exit(llx, 0);
	return (1);
}

int main()
{
	t_llx		*llx;
	t_llx_win	*win;

	llx = llx_init();
	if (!llx)
		return (1);
	win = llx_win_new(llx, 480, 360, "test");
	llx->on_loop = on_loop;
	return (llx_exec(llx));
}
