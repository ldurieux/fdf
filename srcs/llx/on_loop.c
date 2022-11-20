/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:12 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:14 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	size_t		i;
	t_llx_win	*win;

	if (llx->exit_code != -1)
		return (llx_on_exit(llx), 0);
	i = (size_t)-1;
	while (llx->windows[++i])
	{
		win = llx->windows[i];
		mlx_put_image_to_window(llx->mlx, win->mlx_win, win->cache, 0, 0);
	}
	if (llx->on_loop)
		if (!llx->on_loop(llx))
			llx_exit(llx, 1);
	return (0);
}
