/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:18:48 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:18:50 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_INTERNAL_H
# define LLX_INTERNAL_H

# include "llx.h"

void	llx_destroy(t_llx *llx);

int		llx_on_loop(t_llx *llx);

#endif // LLX_INTERNAL_H
