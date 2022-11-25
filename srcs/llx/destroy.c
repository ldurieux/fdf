/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:04 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "llx_internal.h"

void	llx_destroy(t_llx *llx)
{
	size_t	i;

	if (!llx)
		return ;
	if (llx->windows)
	{
		i = (size_t) - 1;
		while (llx->windows[++i])
		{
			if (llx->windows[i]->on_close)
				llx->windows[i]->on_close(llx->windows[i]);
			llx_win_delete(llx->windows[i]);
		}
		free(llx->windows);
	}
	free(llx);
}
