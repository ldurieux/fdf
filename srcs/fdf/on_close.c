/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:29:02 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/25 11:29:03 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_on_close(t_llx_win *win)
{
	t_fdf	*fdf;

	fdf = win->llx->data;
	if (!fdf)
		return ;
	free(fdf->orig_points);
	free(fdf->points);
	free(fdf->colors);
}
