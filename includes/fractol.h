

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

# define NUM_THREADS 8  // Número de hilos a utilizar
# define WIDTH	1000
# define HEIGHT	1000

typedef struct pos
{
	double	x;
	double	y;
	double	zoom;
}	t_position;

typedef struct s_img
{
	void	*img;
	char	*pix;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			(*func)(struct s_data *, int, int);
	int				iter;
	int				color_i;
	unsigned int	color[4];
	t_position		pos;
	t_img			img;
}	t_data;

typedef struct s_thread_data {
    t_data  *data;
    int     start_y;  // Línea inicial
    int     end_y;    // Línea final
} t_thread_data;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

void	draw_mandelbrot(t_data *data, int x, int y);
void	draw_julia(t_data *data, int x, int y);
int		on_keypress(int keysym, t_data *data1);
int		close_on_escape(t_data *data);
void	iterate_screen(t_data *data);
void	ft_put_pixel(t_img img, int x, int y, int color);
double	map(double ratio, double b1, double b2);
double	calculate_ratio(double y, double a1, double a2);
int		calc_bright(t_complex *z, t_complex *c, t_data *d);
int		mouse_hook(int mouse_code, int x, int y, t_data *data);
void	draw_burning_ship(t_data *data, int x, int y);
void	draw_mandelbox(t_data *data, int x, int y);
#endif