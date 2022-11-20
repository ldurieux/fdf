#include "llx.h"
#include "llx_paint.h"
#include "fdf.h"

#include "ft_printf.h"

#define PTS 27
#define WIDTH 480
#define HEIGHT 360

t_vec3	points[PTS] = {
	{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {2.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {2.0f, 0.0f, 1.0f},
	{0.0f, 0.0f, 2.0f}, {1.0f, 1.0f, 2.0f}, {2.0f, 0.0f, 2.0f},
	{0.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 3.0f}, {2.0f, 0.0f, 3.0f},
	{0.0f, 0.0f, 4.0f}, {1.0f, 0.0f, 4.0f}, {2.0f, 0.0f, 4.0f},
	{0.0f, 0.0f, 5.0f}, {1.0f, 0.0f, 5.0f}, {2.0f, 0.0f, 5.0f},
	{0.0f, 0.0f, 6.0f}, {1.0f, 1.0f, 6.0f}, {2.0f, 0.0f, 6.0f},
	{0.0f, 0.0f, 7.0f}, {1.0f, 0.0f, 7.0f}, {2.0f, 0.0f, 7.0f},
	{0.0f, 0.0f, 8.0f}, {1.0f, 0.0f, 8.0f}, {2.0f, 0.0f, 8.0f},
};

t_vec3	axis[3] = {
	{1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}
};

t_mat4x4 *proj;

static t_vec3	rot = (t_vec3){0.5f, 2.1f, -0.3f};
static t_vec3	trans = (t_vec3){0.0f, 0.4f, 15.0f};

void on_key_down(t_llx_win *win, int key)
{
	if(key == 122) //Z
		rot.y += 0.1f;
	else if(key == 115) //S
		rot.y -= 0.1f;
	else if(key == 113) //Q
		rot.x += 0.1f;
	else if(key == 100) //D
		rot.x -= 0.1f;
	else if(key == 101) //E
		rot.z += 0.1f;
	else if(key == 97) //A
		rot.z -= 0.1f;
	else if(key == 65363) //Right
		trans.x -= 0.1f;
	else if(key == 65361) //Left
		trans.x += 0.1f;
	else if(key == 65364) //Down
		trans.z += 0.1f;
	else if(key == 65362) //Up
		trans.z -= 0.1f;
	else if(key == 65365) //Page up
		trans.y += 0.1f;
	else if(key == 65366) //Page Down
		trans.y -= 0.1f;
	else
		ft_printf("%d\n", key);
}

void draw_axis(t_llx_paint *paint, t_mat4x4 *mat_rot)
{
	t_vec3		projected;
	t_point		flat;
	t_point		origin;
	uint32_t	color;

	color = 0xff000000;
	ft_memset(&origin, 0, sizeof(t_point));
	projected = (t_vec3){0, 0, 0};
	fdf_add_vec3(&trans, &projected);
	fdf_mul_vec_mat4x4(&projected, &projected, proj);
	projected.x += 1.0f;
	projected.y += 1.0f;
	projected.x *= 0.5f * WIDTH;
	projected.y *= 0.5f * HEIGHT;
	origin.x = (int)projected.x;
	origin.y = (int)projected.y;
	for (int i = 0; i < 3; i++)
	{
		color >>= 8;
		paint->pen.ucolor = color;
		projected = axis[i];
		fdf_mul_vec_mat4x4(&projected, &projected, mat_rot);
		fdf_add_vec3(&trans, &projected);
		fdf_mul_vec_mat4x4(&projected, &projected, proj);
		projected.x += 1.0f;
		projected.y += 1.0f;
		projected.x *= 0.5f * WIDTH;
		projected.y *= 0.5f * HEIGHT;
		flat.x = (int)projected.x;
		flat.y = (int)projected.y;
		llx_paint_line(paint, origin, flat);
	}
}

int on_loop(t_llx *llx)
{
	t_llx_paint	paint;
	t_llx_win	*win;
	t_mat4x4	mat_rot;

	win = llx->windows[0];
	paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_Black,
			(t_rect){0, 0, WIDTH, HEIGHT}, 0};
	llx_paint_fill(&paint);
	paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_White,
			(t_rect){0, 0, WIDTH, HEIGHT}, 0};

	mat_rot = fdf_rotation_matrix(rot.z, rot.x, rot.y);

	t_vec3 projected[PTS];
	t_point nodes[PTS];
	for (int i = 0; i < PTS; i++)
	{
		projected[i] = points[i];
		projected[i].x /= 10;
		projected[i].y /= 10;
		projected[i].z /= 10;

		fdf_mul_vec_mat4x4(projected + i, projected + i, &mat_rot);
		projected[i].z += trans.z;
		projected[i].y += trans.y;
		projected[i].x += trans.x;

		fdf_mul_vec_mat4x4(projected + i, projected + i, proj);

		projected[i].x += 1.0f;
		projected[i].y += 1.0f;
		projected[i].x *= 0.5f * WIDTH;
		projected[i].y *= 0.5f * HEIGHT;

		nodes[i].x = (int)projected[i].x;
		nodes[i].y = (int)projected[i].y;
	}
	for (int i = 0; i < PTS; i++)
	{
		if (i % 3 != 2)
			llx_paint_line(&paint, nodes[i], nodes[i + 1]);
		if (i / 3 < 8)
			llx_paint_line(&paint, nodes[i], nodes[i + 3]);
	}
	draw_axis(&paint, &mat_rot);
	return (1);
}

int main()
{
	t_llx		*llx;
	t_llx_win	*win;

	t_mat4x4 tmp = fdf_isometric_projection_matrix();
	proj = &tmp;

	llx = llx_init();
	if (!llx)
		return (1);
	win = llx_win_new(llx, WIDTH, HEIGHT, "test");
	win->on_key_down = on_key_down;
	llx->on_loop = on_loop;
	return (llx_exec(llx));
}
