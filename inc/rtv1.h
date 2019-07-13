/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:29:03 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 19:38:14 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# if __linux__
#  define A_KEY 97
#  define W_KEY 119
#  define S_KEY 115
#  define D_KEY 100
#  define Q_KEY 113
#  define E_KEY 101
#  define R_KEY 114
#  define F_KEY 102
#  define Z_KEY 122
#  define C_KEY 99
#  define T_KEY 116
#  define G_KEY 103
#  define ESC_KEY 65307
# else
#  define A_KEY 0
#  define W_KEY 13
#  define S_KEY 1
#  define D_KEY 2
#  define Q_KEY 12
#  define E_KEY 14
#  define R_KEY 15
#  define F_KEY 3
#  define Z_KEY 6
#  define C_KEY 8
#  define T_KEY 17
#  define G_KEY 5
#  define P_KEY 35
#  define ESC_KEY 53
#  define PI 3.14
#  define RED 1
#  define BLUE 2
# endif

# define THREADS_AMOUNT 8
# define BTN_AMOUNT 11

# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "../Frameworks/SDL2.framework/Headers/SDL.h"
# include "../Frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include "../Frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"

/*
**	magic
*/
typedef double		t_dbl4 __attribute__((vector_size(sizeof(double)*4)));

typedef	t_dbl4		t_vec;

typedef t_dbl4		t_color;

/*
**	go full on crutch. LETS GO!!!
*/
typedef struct		s_id_dist
{
	int				id;
	double			dist;
}					t_id_dist;

/*
**	important typedefs
*/
typedef struct		s_pair
{
	double			d1;
	double			d2;
}					t_pair;

typedef struct s_params		t_params;

typedef struct s_obj		t_obj;

typedef struct		s_ray
{
	t_vec			ori;
	t_vec			dir;
}					t_ray;

typedef void		(*t_dist_func)(t_obj *obj, t_ray ray, t_pair *res);

typedef t_vec		(*t_normal_func)(t_obj *obj, t_vec hit, t_params *p);

struct				s_obj
{
	int				is_negative;
	t_vec			center;
	t_vec			dir;
	t_vec			normal;
	float			angle;
	float			radius;
	int				height;
	int				height_up;
	int				height_down;
	t_dist_func		get_dist;
	t_normal_func	get_normal;
	t_color			color;
	float			specular;
	float			reflection;
	float			k;
	SDL_Surface		*texture;
	int				slice_type;
	t_vec			slice_ori;
	t_vec			slice_dir;
};

typedef struct		s_image
{
	void			*image;
	int				*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef struct		s_blender
{
	SDL_Surface		*res;
	Uint32			*p_sur;
	Uint32			*p_sur1;
	Uint32			*p_res;
	t_vec			c_sur;
	t_vec			c_sur1;
	t_vec			c_res;
}					t_blender;

typedef struct		s_camera
{
	t_vec			ori;
	t_vec			dir;
}					t_camera;

typedef struct		s_light
{
	t_vec			ori;
	t_vec			dir;
	float			intensity;
	int				type;
}					t_light;

typedef struct		s_thread
{
	int				id;
	pthread_t		thread_id;
	t_params		*p;
}					t_thread;

struct				s_params
{
	SDL_Window		*win_ptr;
	SDL_Surface		*surface;
	t_camera		*camera;
	t_light			*light_sources;
	t_obj			*obj_arr;
	int				width;
	int				height;
	int				obj_amount;
	int				light_amount;
	float			aspect_ratio;
	float			fov;
	t_ray			tmp_ray;
	SDL_Color		color;
	t_color			env_light;
	char			*light_type;
	t_vec			tmp_light;
	t_id_dist		tmp_i_d;
	int				obj_id;
	double			m;
	int				pixel_view;
	int				reflection_depth;
	int				complex_flag;
	t_vec			complex_ori;
	unsigned int	*pxls;
	int				sign;
	TTF_Font		*font;
	Uint8			anaglyph;
	Uint8			antialiasing;
	Uint8			black;
	SDL_Rect		btn[BTN_AMOUNT];
	SDL_Surface		*ui_window;
	SDL_Surface		*check_icon;
	SDL_Surface		*loading;
	double			light_coef;
	double			dot_product;
	t_vec			light;
	t_pair			res;
};
/*
**	typedef for parser
*/
t_params			*parser(char *line);

/*
**	main.c
*/
void				init(t_params *p);
int					main(int ac, char **av);

/*
**	secondary.c
*/
t_vec				point_at_parameter(double t, t_ray ray);
double				pow2(double a);
int					get_color(t_color color);
t_color				int_to_color(int color);
int					img_put_pixel(t_params *p, int x, int y, int color);

/*
** get_normal.c
*/
t_vec				sphere_normal(t_obj *obj, t_vec hit, t_params *p);
t_vec				cylinder_normal(t_obj *obj, t_vec hit, t_params *p);
t_vec				cone_normal(t_obj *obj, t_vec hit, t_params *p);
t_vec				plane_normal(t_obj *obj, t_vec hit, t_params *p);
t_vec				parabl_normal(t_obj *obj, t_vec hit, t_params *p);

/*
**	hit_or_miss.c
*/
void				shpere_hit(t_obj *obj, t_ray ray, t_pair *res);
void				cylinder_hit(t_obj *obj, t_ray ray, t_pair *res);
void				cone_hit(t_obj *obj, t_ray ray, t_pair *res);
void				plane_hit(t_obj *obj, t_ray ray, t_pair *res);
void				parabl_hit(t_obj *obj, t_ray ray, t_pair *res);

/*
**	render.c
*/
t_color				ray_trace_2(t_vec ori, t_vec dir, int depth, t_params *p);
t_color				ray_trace(float u, float v, t_params *p);
void				pixel_view(int x, int y, int tmp, t_params *p);
t_vec				prepere_dir(int x, int y, t_params *p);
void				render(int id, t_params *p);
void				*prepere_render(void *thr);
void				create_threads(t_params *p);

/*
**	actions.c
*/
t_params			*camera_move(int dir, t_params *p);
t_params			*camera_down_up(int dir, t_params *p);
t_params			*camera_dir_helper(int axis, int sign, t_params *p);
void				camera_dir_2(SDL_Keycode key, t_params *p);
void				camera_dir(SDL_Keycode key, t_params *p);

/*
**	actions_2.c
*/
void				name_screen(char *str, char *tmp, struct tm tm);
void				screen_shot(t_params *p);
int					key_press(SDL_Keycode key, t_params *p);

/*
** rotate.c
*/
void				rotate_x(t_vec *v, float angle);
void				rotate_y(t_vec *v, float angle);
void				rotate_z(t_vec *v, float angle);
void				rotate_xyz(t_vec *v, t_params *p);

/*
** vector_operators_1.c
*/
double				dot(t_vec a, t_vec b);
double				length(t_vec v);
t_vec				cross(t_vec a, t_vec b);
t_vec				unit_vector(t_vec v);
t_vec				reflect(t_vec ray_dir, t_vec normal);

/*
**	vector_operators_2.c
*/
t_vec				to_vec(double val);
int					check_vec(t_vec v);
void				height_edge(t_obj *obj, t_ray ray,
								double rd_cd, t_pair *tmp_res);
int					slice_intersect(double t, t_obj *obj, t_ray ray);
void				move_obj(double val, int xyz, t_params *p);

/*
**	render_text.c
*/
void				render_text(t_params *p, char *str, int x, int y);

/*
**	anaglyph.c
*/
SDL_Surface			*blend_surfaces(SDL_Surface *sur, SDL_Surface *sur1);
void				red_blue_version(SDL_Surface *sur, int color);
void				anaglyph_render(t_params *p);
SDL_Surface			*surface_cpy(SDL_Surface *sur);
void				fill_background(SDL_Surface *background,
													SDL_Surface *scene);

/*
**	anaglyph_2.c
*/
void				render1(t_params *p);
Uint32				map_rgb(t_vec rgb);
void				give_c_res(t_blender *b, SDL_Surface *sur,
						SDL_Surface *sur1);

/*
**	textures.c
*/
t_color				gray_scale(t_color color);
Uint32				get_texture_color(SDL_Surface *texture, int x, int y);
t_color				spherical_mapping(SDL_Surface *texture,
											t_vec hit, t_vec center);
int					antialiasing(double x1, double y1, t_params *p);

/*
**	ui.c
*/
void				set_buttons(t_params *p);
void				wich_shape(t_params *p);
void				render_ui(t_params *p);
int					check_ui(int x, int y);

/*
** pure_trash.c
*/
int					set_pair(t_pair *res, double a, double b);

/*
** shading.c
*/
int					shadow(int i, t_vec hit, t_params *p);
void				diff_spec(int i, t_vec normal, t_params *p);
int					save_me(int i, t_vec hit, t_vec normal, t_params *p);
double				compute_light(t_vec hit, t_vec normal,
										int obj_id, t_params *p);
t_color				shading(t_id_dist obj_id_dist,
										t_vec hit, int depth, t_params *p);

/*
** ray_trace.c
*/
t_color				ray_trace_2(t_vec ori, t_vec dir, int depth, t_params *p);
t_color				ray_trace(float u, float v, t_params *p);

/*
** obj_hit.c
*/
int					compute_quadratic(t_vec tmp, t_pair *res);
int					set_id_dist(int flag, double *dist,
					int tmp_id, t_params *p);
void				obj_hit(int *id, double *dist, t_ray ray, t_params *p);

/*
** sdl_event.c
*/
void				button_helper_2(int btn, t_params *p);
void				button_hendler(int btn, t_params *p);
int					ui_hendler(int x, int y, t_params *p);
void				find_obj(t_vec ori, t_vec dir, t_params *p);
void				sdl_event(t_params *p, SDL_Event *ev);

#endif
