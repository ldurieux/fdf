#include "llx.h"
#include "llx_internal.h"

static void	llx_on_exit(t_llx *llx)
{
	if (llx->on_exit)
		llx->on_exit(llx);
	llx_destroy(llx);
	exit(llx->exit_code);
}

int	llx_on_loop(t_llx *llx)
{
	if (llx->exit_code != -1)
		return (llx_on_exit(llx), 0);
	if (llx->on_loop)
		if (!llx->on_loop(llx))
			llx_exit(llx, 1);
	return (0);
}
