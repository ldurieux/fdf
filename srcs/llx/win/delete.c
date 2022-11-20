/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:14 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:16 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"
#include "llx.h"

void	llx_win_delete(t_llx_win *win)
{
	uint8_t	last_id;
	t_llx	*llx;

	if (!win)
		return ;
	llx = win->llx;
	if (llx->windows[win->id] == win)
	{
		last_id = --llx->last_win_id;
		llx->windows[last_id]->id = win->id;
		llx->windows[win->id] = llx->windows[last_id];
		llx->windows[last_id] = NULL;
		if (llx->last_win_id == 0)
			llx_exit(llx, 0);
	}
	if (win->mlx_win)
		mlx_destroy_window(llx->mlx, win->mlx_win);
	if (win->cache)
		mlx_destroy_image(llx->mlx, win->cache);
	free(win);
}
