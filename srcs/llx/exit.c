#include "llx.h"

void	llx_exit(t_llx *llx, int exit_code)
{
	if (exit_code == -1)
		exit_code = 1;
	llx->exit_code = exit_code;
}
