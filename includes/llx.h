#ifndef LLX_H
# define LLX_H

# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "llx_win.h"

# define LLX_MAX_WIN	255

typedef struct s_llx_win	t_llx_win;

typedef struct s_llx
{
	mlx_ptr_t	*mlx;
	t_llx_win	**windows;
	uint8_t		last_win_id;
	int			(*on_loop)(struct s_llx *llx);
	void		(*on_exit)(struct s_llx *llx);
	int			exit_code;
}	t_llx;

t_llx	*llx_init(void);
int		llx_exec(t_llx *llx);
void	llx_exit(t_llx *llx, int exit_code);

#endif // LLX_H
