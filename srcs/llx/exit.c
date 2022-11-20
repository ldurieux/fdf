/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:08 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:17:10 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx.h"

void	llx_exit(t_llx *llx, int exit_code)
{
	if (exit_code == -1)
		exit_code = 1;
	llx->exit_code = exit_code;
}