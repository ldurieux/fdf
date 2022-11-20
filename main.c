#include "llx.h"
#include "llx_paint.h"
#include "fdf.h"

#define PTS 3
#define WIDTH 480
#define HEIGHT 360

float off = 0;

t_vec3	points[PTS] = {
	{0.0f, 0.0f, 0.0f},    {0.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 0.0f},
};

t_mat4x4 *proj;

int on_loop(t_llx *llx)
{
	t_llx_paint	paint;
	t_llx_win	*win;

	win = llx->windows[0];
	paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_Black,
			(t_rect){0, 0, WIDTH, HEIGHT}, 0};
	llx_paint_fill(&paint);
	paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_White,
			(t_rect){0, 0, WIDTH, HEIGHT}, 0};

	t_vec3 projected[PTS];
	t_point nodes[PTS];
	for (int i = 0; i < PTS; i++)
	{
		projected[i] = points[i];
		projected[i].z += 3.0f;

		fdf_mul_vec_mat4x4(projected + i, projected + i, proj);

		projected[i].x += 1.0f;
		projected[i].y += off;
		projected[i].x *= 0.5f * WIDTH;
		projected[i].y *= 0.5f * HEIGHT;

		nodes[i].x = (int)projected[i].x;
		nodes[i].y = (int)projected[i].y;
	}
	llx_paint_tri(&paint, nodes[0], nodes[1], nodes[2]);
	off += 0.01f;
	return (1);
}

void on_exit(t_llx *llx)
{
	return ;
}

int main()
{
	t_llx		*llx;
	t_llx_win	*win;

	t_mat4x4 tmp = fdf_projection_matrix();
	proj = &tmp;

	llx = llx_init();
	if (!llx)
		return (1);
	win = llx_win_new(llx, WIDTH, HEIGHT, "test");
	llx->on_loop = on_loop;
	llx->on_exit = on_exit;
	return (llx_exec(llx));
}
