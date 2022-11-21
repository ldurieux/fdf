/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:18:45 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:18:47 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_H
# define LLX_H

# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "mlx.h"
# include "llx_win.h"

# define LLX_MAX_WIN	255

typedef struct s_llx_win	t_llx_win;

typedef struct s_point
{
	int32_t	x;
	int32_t	y;
}	t_point;

typedef struct s_size
{
	int32_t	width;
	int32_t	height;
}	t_size;

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
	void		*mlx;
	t_llx_win	**windows;
	uint8_t		last_win_id;
	int			(*on_loop)(struct s_llx *llx);
	void		(*on_exit)(struct s_llx *llx);
	int			exit_code;
	void		*data;
}	t_llx;

t_llx	*llx_init(void);
int		llx_exec(t_llx *llx);
void	llx_exit(t_llx *llx, int exit_code);

#endif // LLX_H
