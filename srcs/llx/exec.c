#include "llx.h"
#include "llx_internal.h"

int		llx_exec(t_llx *llx)
{
	mlx_loop(llx->mlx);
	return (0);
}
