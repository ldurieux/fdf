/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_win_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:18:56 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:19:00 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_WIN_INTERNAL_H
# define LLX_WIN_INTERNAL_H

# include "ft_printf.h"

typedef struct s_llx_win	t_llx_win;

void	llx_on_key_down(int keycode, t_llx_win *ptr);
void	llx_on_key_up(int keycode, t_llx_win *ptr);
void	llx_on_mouse_down(int button, int x, int y, t_llx_win *ptr);
void	llx_on_mouse_up(int button, int x, int y, t_llx_win *ptr);
void	llx_on_mouse_move(int x, int y, t_llx_win *ptr);
void	llx_on_enter(t_llx_win *ptr);
void	llx_on_leave(t_llx_win *ptr);
void	llx_on_close(t_llx_win *ptr);

int		llx_win_key_down_idx(t_llx_win *win, int key);

#endif // LLX_WIN_INTERNAL_H
