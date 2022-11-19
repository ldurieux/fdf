#include "llx.h"
#include "llx_paint.h"

static int test = 0;

int on_loop(t_llx *llx)
{
	++test;
	if (test == -1)
		llx_exit(llx, 0);
	return (1);
}

int main()
{
	t_llx		*llx;
	t_llx_win	*win;
	t_llx_paint	paint;

	llx = llx_init();
	if (!llx)
		return (1);
	win = llx_win_new(llx, 480, 360, "test");
	paint = (t_llx_paint){win->cache, Llx_Transparent, Llx_White, (t_rect){0, 0, 480, 360}, 0};
	llx_paint_fill(&paint);

	paint.pen.ucolor = Llx_Blue;
	llx_paint_line(&paint, (t_point){10, 10}, (t_point){300, 150});
	paint.flags |= Paint_Flag_Antialiasing;
	llx_paint_line(&paint, (t_point){10, 20}, (t_point){300, 160});

	llx->on_loop = on_loop;
	return (llx_exec(llx));
}
