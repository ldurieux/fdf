#ifndef LLX_WIN_H
# define LLX_WIN_H

#include <stdint.h>
#include "libft.h"
#include "mlx_int.h"

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

typedef struct s_llx_win
{
	void	*mlx_win;
	t_llx	*llx;
	uint8_t	id;
	int		width;
	int		height;
	t_img	*cache;
}	t_llx_win;

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title);
void		llx_win_delete(t_llx_win *win);

#endif // LLX_WIN_H
