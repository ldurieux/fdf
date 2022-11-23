/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:07:05 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/23 14:07:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"
#include "llx_win_internal.h"

int	llx_win_is_key_down(t_llx_win *win, int key)
{
	int	i;

	i = -1;
	while (++i <= win->last_key_idx)
		if (win->keys[i] == key)
			return (1);
	return (0);
}

int	llx_win_key_down_idx(t_llx_win *win, int key)
{
	int	i;

	i = -1;
	while (++i <= win->last_key_idx)
		if (win->keys[i] == key)
			return (i);
	return (-1);
}
