
#ifndef FRACTOL_H
#  define FRACTOL_H
# include <math.h>
# include <mlx.h>

# define W 800
# define H 800

/*--------------Posicion en el fractal---------------*/
typedef struct possition
{
    double x; 
    double y; 
    double zoom; 
    
}   t_position;

/*---------------Numeros Imaginarios------------------*/
/*se crea una recta en paralelo y el fractal va ella*/
typedef struct s_imaginary
{
    double      real; 
    double      imaginary; 
}      t_imaginary;


/*----------------Estructura de imagen------------------*/

typedef struct s_imagen
{
    void    *imagen;
    char    *pixel; 
    int     bits; 
    int     l_len; 
    int     endian;//sin usar
}       t_imagen; 

/*-------------------mlx data--------------------------*/

typedef struct s_mlx_data
{
    void	*mlx_pointer; //apuntar a la MiniLibX
	void	*windows_generator_pointer;//manipulacion de ventanasw
    void     (*func)(struct s_data *, int, int);
	int		iterador;
	int		color_index;
	unsigned int	color[4];
	t_position	position;
	t_imagen 	imagen;
}       t_mlx_data;  //nombre

/*-----------------------Fractol Build------------------*/

int     key_handle(int keys, t_mlx_data *data1);
int		mouse_vision(int mouse, int x, int y, t_mlx_data *data);
int     escape(t_mlx_data *data); 
void	iterator(t_mlx_data *data);
void    pixel_put(t_imagen, int x,int y, int color); //lo que colorea
double  imaginary_converter(double current, double n1, double n2); //parseo convertidor
double  imaginaru_calculator(double y, double n3, double n4); //calculo paralela
int     deep(t_imaginary *z, t_imaginary *c, t_mlx_data *d);

/* ------------------------Fractals----------------------*/

void	mandelgroot(t_mlx_data *data, int x, int y); 
void	julia(t_mlx_data *data, int x, int y); 
void    burning_ship(t_mlx_data *data, int x, int y); 

#endif
