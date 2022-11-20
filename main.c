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

	paint = (t_llx_paint){win->cache, {Llx_Transparent}, {Llx_White}, (t_rect){0, 0, 480, 360}, 0};
	llx_paint_fill(&paint);

	paint = (t_llx_paint){win->cache, {Llx_Transparent}, {Llx_Red}, (t_rect){0, 0, 480, 360}, 0};
	for (int i = 0; i < 100; i++)
		llx_paint_pixel(&paint, (t_point){i, 0});
	paint = (t_llx_paint){win->cache, {Llx_Transparent}, {Llx_Green}, (t_rect){0, 0, 480, 360}, 0};
	for (int i = 0; i < 100; i++)
		llx_paint_pixel(&paint, (t_point){i, 1});
	paint = (t_llx_paint){win->cache, {Llx_Transparent}, {Llx_Blue}, (t_rect){0, 0, 480, 360}, 0};
	for (int i = 0; i < 100; i++)
		llx_paint_pixel(&paint, (t_point){i, 2});

	paint = (t_llx_paint){win->cache, {Llx_Transparent}, {Llx_Black}, (t_rect){0, 0, 480, 360}, 0};
	llx_paint_line(&paint, (t_point){10, 10}, (t_point){200, 200});

	llx->on_loop = on_loop;
	return (llx_exec(llx));
}
