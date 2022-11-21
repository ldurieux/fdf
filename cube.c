#include "llx.h"
#include "llx_win.h"
#include "llx_3d.h"
#include "llx_paint.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_triangle
{
	t_vec3 pts[3];
}	t_triangle;

#define TRI_COUNT 12
static t_triangle triangles[TRI_COUNT] = {
	{ (t_vec3){0.0f, 0.0f, 0.0f},   (t_vec3){0.0f, 1.0f, 0.0f},    (t_vec3){1.0f, 1.0f, 0.0f} },
	{ (t_vec3){0.0f, 0.0f, 0.0f},   (t_vec3){1.0f, 1.0f, 0.0f},    (t_vec3){1.0f, 0.0f, 0.0f} },
	{ (t_vec3){1.0f, 0.0f, 0.0f},   (t_vec3){1.0f, 1.0f, 0.0f},    (t_vec3){1.0f, 1.0f, 1.0f} },
	{ (t_vec3){1.0f, 0.0f, 0.0f},   (t_vec3){1.0f, 1.0f, 1.0f},    (t_vec3){1.0f, 0.0f, 1.0f} },
	{ (t_vec3){1.0f, 0.0f, 1.0f},   (t_vec3){1.0f, 1.0f, 1.0f},    (t_vec3){0.0f, 1.0f, 1.0f} },
	{ (t_vec3){1.0f, 0.0f, 1.0f},   (t_vec3){0.0f, 1.0f, 1.0f},    (t_vec3){0.0f, 0.0f, 1.0f} },
	{ (t_vec3){0.0f, 0.0f, 1.0f},   (t_vec3){0.0f, 1.0f, 1.0f},    (t_vec3){0.0f, 1.0f, 0.0f} },
	{ (t_vec3){0.0f, 0.0f, 1.0f},   (t_vec3){0.0f, 1.0f, 0.0f},    (t_vec3){0.0f, 0.0f, 0.0f} },
	{ (t_vec3){0.0f, 1.0f, 0.0f},   (t_vec3){0.0f, 1.0f, 1.0f},    (t_vec3){1.0f, 1.0f, 1.0f} },
	{ (t_vec3){0.0f, 1.0f, 0.0f},   (t_vec3){1.0f, 1.0f, 1.0f},    (t_vec3){1.0f, 1.0f, 0.0f} },
	{ (t_vec3){1.0f, 0.0f, 1.0f},   (t_vec3){0.0f, 0.0f, 1.0f},    (t_vec3){0.0f, 0.0f, 0.0f} },
	{ (t_vec3){1.0f, 0.0f, 1.0f},   (t_vec3){0.0f, 0.0f, 0.0f},    (t_vec3){1.0f, 0.0f, 0.0f} },
};

static t_mat4x4	mat_proj;
static t_vec3	rot;

void cube_key_down(t_llx_win *win, int key)
{
	if(key == 13) //W
		rot.x -= 0.1f;
	else if(key == 1) //S
		rot.x += 0.1f;
	else if(key == 0) //A
		rot.y += 0.1f;
	else if(key == 2) //D
		rot.y -= 0.1f;
	else if(key == 14) //E
		rot.z += 0.1f;
	else if(key == 12) //Q
		rot.z -= 0.1f;
}

void	paint_line_util(t_llx_paint *paint, t_vec3 p1, t_vec3 p2)
{
	t_point p2d_1;
	t_point	p2d_2;

	p2d_1.x = (int32_t)p1.x;
	p2d_1.y = (int32_t)p1.y;
	p2d_2.x = (int32_t)p2.x;
	p2d_2.y = (int32_t)p2.y;
	llx_paint_line(paint, p2d_1, p2d_2);
}

int cube_loop(t_llx *llx)
{
	t_llx_win	*win;
	t_llx_paint paint;

	win = llx->windows[0];
	paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_Black,
			(t_rect){0, 0, WIDTH, HEIGHT}, 0};
	llx_paint_fill(&paint);
	paint = (t_llx_paint){llx->windows[0]->cache, Llx_Transparent, Llx_White,
			(t_rect){0, 0, WIDTH, HEIGHT}, 0};

	t_triangle	projected;
	t_mat4x4	mat_rotZ;
	ft_memset(mat_rotZ.m, 0, sizeof(float) * 16);
	mat_rotZ.m[0][0] = cosf(rot.z);
	mat_rotZ.m[0][1] = sinf(rot.z);
	mat_rotZ.m[1][0] = -sinf(rot.z);
	mat_rotZ.m[1][1] = cosf(rot.z);
	mat_rotZ.m[2][2] = 1;
	mat_rotZ.m[3][3] = 1;

	t_mat4x4	mat_rotX;
	ft_memset(mat_rotX.m, 0, sizeof(float) * 16);
	mat_rotX.m[0][0] = 1;
	mat_rotX.m[1][1] = cosf(rot.x);
	mat_rotX.m[1][2] = sinf(rot.x);
	mat_rotX.m[2][1] = -sinf(rot.x);
	mat_rotX.m[2][2] = cosf(rot.x);
	mat_rotX.m[3][3] = 1;

	t_mat4x4	mat_rotY;
	ft_memset(mat_rotY.m, 0, sizeof(float) * 16);
	mat_rotY.m[0][0] = cosf(rot.y);
	mat_rotY.m[0][2] = -sinf(rot.y);
	mat_rotY.m[1][1] = 1;
	mat_rotY.m[2][0] = sinf(rot.y);
	mat_rotY.m[2][2] = cosf(rot.y);
	mat_rotY.m[3][3] = 1;

//	t_mat4x4	mat_rot = llx_rotation_matrix(rot.y, rot.x, rot.z);

	for (int i = 0; i < TRI_COUNT; i++)
	{
		projected = triangles[i];

		for (int j = 0; j < 3; j++)
		{
			// Rotate
			llx_mul_vec3_mat4x4(&mat_rotZ, projected.pts + j);
			llx_mul_vec3_mat4x4(&mat_rotX, projected.pts + j);
			llx_mul_vec3_mat4x4(&mat_rotY, projected.pts + j);
//			llx_mul_vec3_mat4x4(&mat_rot, projected.pts + j);
			// Offset into the screen
			projected.pts[j].z += 3.0f;
			// Project triangles from 3D --> 2D
			llx_mul_vec3_mat4x4(&mat_proj, projected.pts + j);
		}

		// Scale into view
		for (int j = 0; j < 3; j++)
		{
			projected.pts[j].x += 1.0f;
			projected.pts[j].y += 1.0f;
			projected.pts[j].x *= 0.5f * WIDTH;
			projected.pts[j].y *= 0.5f * HEIGHT;
		}

		paint_line_util(&paint, projected.pts[0], projected.pts[1]);
		paint_line_util(&paint, projected.pts[1], projected.pts[2]);
		paint_line_util(&paint, projected.pts[2], projected.pts[0]);
	}
	return (1);
}

int cube()
{
	t_llx		*llx;
	t_llx_win	*win;

//	mat_proj = llx_projection_matrix((t_size){WIDTH, HEIGHT});
	mat_proj = llx_isometric_projection_matrix();
	rot = (t_vec3){0, 0, 0};

	for (int i = 0; i < TRI_COUNT; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			triangles[i].pts[j].x -= 0.5f;
			triangles[i].pts[j].y -= 0.5f;
			triangles[i].pts[j].z -= 0.5f;
			triangles[i].pts[j].x *= 0.5f;
			triangles[i].pts[j].y *= 0.5f;
			triangles[i].pts[j].z *= 0.5f;
		}
	}

	llx = llx_init();
	if (!llx)
		return (1);
	llx->data = NULL;
	win = llx_win_new(llx, WIDTH, HEIGHT, "test");
	win->on_key_down = cube_key_down;
	llx->on_loop = cube_loop;
	return (llx_exec(llx));
}
