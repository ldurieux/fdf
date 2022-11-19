#include "llx.h"
#include "llx_internal.h"

static t_llx	*on_error(t_llx *llx)
{
	llx_destroy(llx);
	return (NULL);
}

t_llx	*llx_init(void)
{
	t_llx		*llx;

	llx = malloc(sizeof(t_llx));
	if (!llx)
		return (on_error(NULL));
	llx->last_win_id = 0;
	llx->on_loop = NULL;
	llx->on_exit = NULL;
	llx->exit_code = -1;
	llx->mlx = mlx_init();
	llx->windows = ft_calloc(sizeof(t_llx_win), LLX_MAX_WIN);
	if (!llx->mlx || !llx->windows)
		return (on_error(llx));
	mlx_loop_hook(llx->mlx, llx_on_loop, llx);
	return (llx);
}
