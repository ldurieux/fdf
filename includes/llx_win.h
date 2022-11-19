#ifndef LLX_WIN_H
# define LLX_WIN_H

#include <stdint.h>
#include "libft.h"

typedef struct s_llx	t_llx;

typedef struct s_llx_win
{
	void	*mlx_win;
	t_llx	*llx;
	uint8_t	id;
	int		width;
	int		height;
	void	*cache;
	void	(*)();
}	t_llx_win;

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title);
void		llx_win_delete(t_llx_win *win);

#endif // LLX_WIN_H
