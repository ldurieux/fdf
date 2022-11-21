#include "llx.h"
#include "llx_paint.h"
#include "llx_3d.h"
#include "fdf.h"

#include "ft_printf.h"
/*
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

t_size	half_win_size = (t_size){WIDTH / 2, HEIGHT / 2};

static t_vec3	rot = (t_vec3){0.5f, 2.1f, -0.3f};
static t_vec3	trans = (t_vec3){0.0f, 0.4f, 15.0f};

void on_key_down(t_llx_win *win, int key)
{
	if(key == 13) //W
		rot.y += 0.1f;
	else if(key == 1) //S
		rot.y -= 0.1f;
	else if(key == 0) //A
		rot.x += 0.1f;
	else if(key == 2) //D
		rot.x -= 0.1f;
	else if(key == 14) //E
		rot.z += 0.1f;
	else if(key == 12) //Q
		rot.z -= 0.1f;
	else if(key == 124) //Right
		trans.x -= 0.1f;
	else if(key == 123) //Left
		trans.x += 0.1f;
	else if(key == 125) //Down
		trans.z += 0.1f;
	else if(key == 126) //Up
		trans.z -= 0.1f;
	else if(key == 116) //Page up
		trans.y += 0.1f;
	else if(key == 121) //Page Down
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
	llx_add_vec3(&trans, &projected);
	llx_mul_vec3_mat4x4(proj, &projected);
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
		llx_mul_vec3_mat4x4(mat_rot, &projected);
		llx_add_vec3(&trans, &projected);
		llx_mul_vec3_mat4x4(proj, &projected);
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

	mat_rot = llx_rotation_matrix(rot.z, rot.x, rot.y);

	t_vec3 projected[PTS];
	t_point nodes[PTS];
	for (int i = 0; i < PTS; i++)
	{
		projected[i] = points[i];
		projected[i].x /= 10;
		projected[i].y /= 10;
		projected[i].z /= 10;

		llx_project_vec3(projected + i, &trans, &mat_rot, proj);
		nodes[i] = llx_vec3_to_point(projected + i, half_win_size);
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

	t_mat4x4 tmp = llx_isometric_projection_matrix();
	proj = &tmp;

	llx = llx_init();
	if (!llx)
		return (1);
	win = llx_win_new(llx, WIDTH, HEIGHT, "test");
	win->on_key_down = on_key_down;
	llx->on_loop = on_loop;
	return (llx_exec(llx));
}
*/

void on_key_down(t_llx_win *win, int key)
{
	t_vec3	*rot;
	t_vec3	*trans;

	rot = &((t_fdf *)win->llx->data)->rot;
	trans = &((t_fdf *)win->llx->data)->trans;
	if(key == 13) //W
		rot->y += 0.1f;
	else if(key == 1) //S
		rot->y -= 0.1f;
	else if(key == 0) //A
		rot->x += 0.1f;
	else if(key == 2) //D
		rot->x -= 0.1f;
	else if(key == 14) //E
		rot->z += 0.1f;
	else if(key == 12) //Q
		rot->z -= 0.1f;
	else if(key == 124) //Right
		trans->x -= 0.1f;
	else if(key == 123) //Left
		trans->x += 0.1f;
	else if(key == 125) //Down
		trans->z += 0.1f;
	else if(key == 126) //Up
		trans->z -= 0.1f;
	else if(key == 116) //Page up
		trans->y += 0.1f;
	else if(key == 121) //Page Down
		trans->y -= 0.1f;
}

static void	setup_paint(t_llx *llx, t_llx_paint *paint, t_fdf *fdf)
{
	t_llx_win	*win;

	win = llx->windows[0];
	*paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_Black,
			(t_rect){0, 0, fdf->win_size.width, fdf->win_size.height}, 0};
	llx_paint_fill(paint);
	*paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_White,
			(t_rect){0, 0, fdf->win_size.width, fdf->win_size.height}, 0};
}

static int	project_points(t_fdf *fdf, t_point **points)
{
	t_vec3		*projected;
	size_t		count;
	size_t		idx;
	t_mat4x4	mat_rot;
	t_size		half_win_size;

	half_win_size = fdf->win_size;
	half_win_size.width /= 2;
	half_win_size.height /= 2;
	mat_rot = llx_rotation_matrix(fdf->rot.y, fdf->rot.x, fdf->rot.z);
	count = (size_t)fdf->map_size.width * (size_t)fdf->map_size.height;
	idx = (size_t)-1;
	projected = malloc(sizeof(t_vec3) * count);
	if (!projected)
		return (0);
	*points = malloc(sizeof(t_point) * count);
	if (!*points)
	{
		free(projected);
		return (0);
	}
	while (++idx < count)
	{
		projected[idx] = fdf->points[idx];
		llx_project_vec3(projected + idx, &fdf->trans, &mat_rot, &fdf->proj_matrix);
		(*points)[idx] = llx_vec3_to_point(projected + idx, half_win_size);
	}
	free(projected);
	return (1);
}

static void	draw_fdf(t_llx_paint *paint, t_fdf *fdf, t_point *points)
{
	int32_t	idx;
	int32_t	count;
	t_size	map_size;

	map_size = fdf->map_size;
	count = map_size.width * map_size.height;
	idx = -1;
	while (++idx < count)
	{
		paint->pen = fdf->colors[idx];
		if (idx % map_size.width != map_size.width - 1)
			llx_paint_line(paint, points[idx], points[idx + 1]);
		if (idx / map_size.width < map_size.height - 1)
			llx_paint_line(paint, points[idx], points[idx + map_size.width]);
	}
}

int on_loop(t_llx *llx)
{
	t_llx_paint	paint;
	t_point		*points;

	setup_paint(llx, &paint, llx->data);
	if (!project_points(llx->data, &points))
		return (0);
	draw_fdf(&paint, llx->data, points);
	//draw_axis(&paint, &mat_rot);
	free(points);
	return (1);
}

static int	start_llx(t_fdf *fdf)
{
	t_llx		*llx;
	t_llx_win	*win;

	llx = llx_init();
	if (!llx)
		return (1);
	llx->data = fdf;
	win = llx_win_new(llx, fdf->win_size.width, fdf->win_size.height, "test");
	win->on_key_down = on_key_down;
	llx->on_loop = on_loop;
	return (llx_exec(llx));
}

int cube();

int main()
{
	return (cube());

	t_fdf	fdf;
	float	ratio;
	char	*path = "/Users/ldurieux/project/42/llx/test_maps/cube.fdf";

	if (!fdf_read_file(path, &fdf.points, &fdf.colors, &fdf.map_size))
		return (1);
	ratio = fdf.map_size.width;
	if (ratio < fdf.map_size.height)
		ratio = fdf.map_size.height;
	for (int i = 0; i < fdf.map_size.width * fdf.map_size.height; i++)
	{
		fdf.points[i].x /= ratio;
		fdf.points[i].z /= ratio;
		fdf.points[i].y /= ratio;
	}
	fdf.win_size = (t_size){1920, 1080};
//	fdf.rot = (t_vec3){0.5f, 2.1f, -0.3f};
//	fdf.trans = (t_vec3){0.0f, 0.4f, 15.0f};
	fdf.rot = (t_vec3){0.0f, 0.0f, M_PI};
	fdf.trans = (t_vec3){0.0f, 0.0f, 7.0f};
//	fdf.proj_matrix = llx_isometric_projection_matrix();
	fdf.proj_matrix = llx_projection_matrix(fdf.win_size);
	return (start_llx(&fdf));
}
