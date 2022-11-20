/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:18 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win_internal.h"
#include "llx_win.h"

void	llx_on_enter(t_llx_win *ptr)
{
}

void	llx_on_leave(t_llx_win *ptr)
{
}

void	llx_on_close(t_llx_win *ptr)
{
	llx_win_delete(ptr);
}
