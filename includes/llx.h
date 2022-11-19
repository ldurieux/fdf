#ifndef LLX_H
# define LLX_H

# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "llx_win.h"

# define LLX_MAX_WIN	255

# ifdef __gnu_linux__
typedef t_xvar	mlx_ptr_t;
typedef t_win_list	mlx_win_list_t;
# endif

typedef struct s_llx_win	t_llx_win;

typedef struct s_point
{
	int32_t	x;
	int32_t	y;
}	t_point;

typedef struct s_pointF
{
	float	x;
	float	y;
}	t_pointF;

typedef struct s_rect
{
	int32_t	x;
	int32_t	y;
	int32_t	width;
	int32_t	height;
}	t_rect;

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
