#include "llx_internal.h"

void	llx_destroy(t_llx *llx)
{
	size_t	i;

	if (!llx)
		return ;
	if (llx->windows)
	{
		i = (size_t)-1;
		while (llx->windows[++i])
			llx_win_delete(llx->windows[i]);
		free(llx->windows);
	}
	if (llx->mlx)
		mlx_destroy_display(llx->mlx);
	free(llx->mlx);
	free(this);
}
