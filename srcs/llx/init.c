/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:10 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	ft_memset(llx, 0, sizeof(t_llx));
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
