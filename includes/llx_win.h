/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:18:54 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/20 13:18:55 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_WIN_H
# define LLX_WIN_H

# include <stdint.h>
# include "libft.h"

# define MAX_KEY_IDX 127

typedef struct s_llx	t_llx;

enum e_event
{
	LlxEvt_KeyPress			= 2,
	LlxEvt_KeyRelease		= 3,
	LlxEvt_ButtonPress		= 4,
	LlxEvt_ButtonRelease	= 5,
	LlxEvt_MotionNotify		= 6,
	LlxEvt_EnterNotify		= 7,
	LlxEvt_LeaveNotify		= 8,
	LlxEvt_FocusIn			= 9,
	LlxEvt_FocusOut			= 10,
	LlxEvt_KeymapNotify		= 11,
	LlxEvt_Expose			= 12,
	LlxEvt_GraphicsExpose	= 13,
	LlxEvt_NoExpose			= 14,
	LlxEvt_VisibilityNotify	= 15,
	LlxEvt_CreateNotify		= 16,
	LlxEvt_DestroyNotify	= 17,
	LlxEvt_UnmapNotify		= 18,
	LlxEvt_MapNotify		= 19,
	LlxEvt_MapRequest		= 20,
	LlxEvt_ReparentNotify	= 21,
	LlxEvt_ConfigureNotify	= 22,
	LlxEvt_ConfigureRequest	= 23,
	LlxEvt_GravityNotify	= 24,
	LlxEvt_ResizeRequest	= 25,
	LlxEvt_CirculateNotify	= 26,
	LlxEvt_CirculateRequest	= 27,
	LlxEvt_PropertyNotify	= 28,
	LlxEvt_SelectionClear	= 29,
	LlxEvt_SelectionRequest	= 30,
	LlxEvt_SelectionNotify	= 31,
	LlxEvt_ColormapNotify	= 32,
	LlxEvt_ClientMessage	= 33,
	LlxEvt_MappingNotify	= 34,
	LlxEvt_GenericEvent		= 35,
	LlxEvt_LASTEvent		= 36,
};

enum e_mask
{
	LlxMsk_NoEvent				= 0x0,
	LlxMsk_KeyPress				= 0x1,
	LlxMsk_KeyRelease			= 0x2,
	LlxMsk_ButtonPress			= 0x4,
	LlxMsk_ButtonRelease		= 0x8,
	LlxMsk_EnterWindow			= 0x10,
	LlxMsk_LeaveWindow			= 0x20,
	LlxMsk_PointerMotion		= 0x40,
	LlxMsk_PointerMotionHint	= 0x80,
	LlxMsk_Button1Motion		= 0x100,
	LlxMsk_Button2Motion		= 0x200,
	LlxMsk_Button3Motion		= 0x400,
	LlxMsk_Button4Motion		= 0x800,
	LlxMsk_Button5Motion		= 0x1000,
	LlxMsk_ButtonMotion			= 0x2000,
	LlxMsk_KeymapState			= 0x4000,
	LlxMsk_Exposure				= 0x8000,
	LlxMsk_VisibilityChange		= 0x10000,
	LlxMsk_StructureNotify		= 0x20000,
	LlxMsk_ResizeRedirect		= 0x40000,
	LlxMsk_SubstructureNotify	= 0x80000,
	LlxMsk_SubstructureRedirect	= 0x100000,
	LlxMsk_FocusChange			= 0x200000,
	LlxMsk_PropertyChange		= 0x400000,
	LlxMsk_ColormapChange		= 0x800000,
	LlxMsk_OwnerGrabButton		= 0x1000000,
};

# ifdef __gnu_linux__

enum e_key
{
	LlxKey_A = 97,
	LlxKey_B = 98,
	LlxKey_C = 99,
	LlxKey_D = 100,
	LlxKey_E = 101,
	LlxKey_F = 102,
	LlxKey_G = 103,
	LlxKey_H = 104,
	LlxKey_I = 105,
	LlxKey_J = 106,
	LlxKey_K = 107,
	LlxKey_L = 108,
	LlxKey_M = 109,
	LlxKey_N = 110,
	LlxKey_O = 111,
	LlxKey_P = 112,
	LlxKey_Q = 113,
	LlxKey_R = 114,
	LlxKey_S = 115,
	LlxKey_T = 116,
	LlxKey_U = 117,
	LlxKey_V = 118,
	LlxKey_W = 119,
	LlxKey_X = 120,
	LlxKey_Y = 121,
	LlxKey_Z = 122,
	LlxKey_Left		= 65361,
	LlxKey_Up		= 65362,
	LlxKey_Right	= 65363,
	LlxKey_Down		= 65364,
	LlxKey_Plus		= 65451,
	LlxKey_Minus	= 65453,
	LlxKey_0 = 224,
	LlxKey_1 = 38,
	LlxKey_2 = 233,
	LlxKey_3 = 34,
	LlxKey_4 = 39,
	LlxKey_5 = 40,
	LlxKey_6 = 45,
	LlxKey_7 = 232,
	LlxKey_8 = 95,
	LlxKey_9 = 231,
};
# else

enum e_key
{
	LlxKey_A = 0,
	LlxKey_B = 11,
	LlxKey_C = 8,
	LlxKey_D = 2,
	LlxKey_E = 14,
	LlxKey_F = 3,
	LlxKey_G = 5,
	LlxKey_H = 4,
	LlxKey_I = 34,
	LlxKey_J = 38,
	LlxKey_K = 40,
	LlxKey_L = 37,
	LlxKey_M = 46,
	LlxKey_N = 45,
	LlxKey_O = 31,
	LlxKey_P = 35,
	LlxKey_Q = 12,
	LlxKey_R = 15,
	LlxKey_S = 1,
	LlxKey_T = 17,
	LlxKey_U = 32,
	LlxKey_V = 9,
	LlxKey_W = 13,
	LlxKey_X = 7,
	LlxKey_Y = 16,
	LlxKey_Z = 6,
	LlxKey_Left		= 123,
	LlxKey_Up		= 126,
	LlxKey_Right	= 124,
	LlxKey_Down		= 125,
	LlxKey_Plus		= 69,
	LlxKey_Minus	= 78,
	LlxKey_0 = 29,
	LlxKey_1 = 18,
	LlxKey_2 = 19,
	LlxKey_3 = 20,
	LlxKey_4 = 21,
	LlxKey_5 = 23,
	LlxKey_6 = 22,
	LlxKey_7 = 26,
	LlxKey_8 = 28,
	LlxKey_9 = 25,
};

# endif

typedef struct s_llx_win
{
	void	*mlx_win;
	t_llx	*llx;
	uint8_t	id;
	int		width;
	int		height;
	int		last_key_idx;
	int		keys[128];
	void	*cache;
	void	(*on_key_down)(struct s_llx_win *win, int keycode);
	void	(*on_key_up)(struct s_llx_win *win, int keycode);
	void	(*on_mouse_down)(struct s_llx_win *win, int button, int x, int y);
	void	(*on_mouse_up)(struct s_llx_win *win, int button, int x, int y);
	void	(*on_mouse_move)(struct s_llx_win *win, int x, int y);
	void	(*on_enter)(struct s_llx_win *win);
	void	(*on_leave)(struct s_llx_win *win);
	void	(*on_close)(struct s_llx_win *win);
}	t_llx_win;

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title);
void		llx_win_delete(t_llx_win *win);
int			llx_win_is_key_down(t_llx_win *win, int key);

#endif // LLX_WIN_H
