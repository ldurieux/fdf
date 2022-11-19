#include "llx.h"

int		llx_exec(t_llx *llx)
{
	int	exit_code;

	mlx_loop(llx->mlx);
	exit_code = llx->exit_code;
	llx_destroy(llx);
	return (exit_code);
}
