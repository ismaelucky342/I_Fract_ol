NAME	= fractol

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

MLX_PATH	= mlx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC			=	-I ./includes/\
				-I ./libft/\
				-I ./mlx/

SRC_PATH	=	src/
SRC			=	main.c \
				render.c \
				mandelbrot.c \
				julia.c \
				window_settings.c 

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibX..."
	@make -C $(MLX_PATH)


$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."
	@echo " "
	@echo "██╗  ██╗██████╗     ███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗      "
	@echo "██║  ██║╚════██╗    ██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║      "
	@echo "███████║ █████╔╝    █████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║      "
	@echo "╚════██║██╔═══╝     ██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║      "
	@echo "     ██║███████╗    ██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗ "
	@echo "     ╚═╝╚══════╝    ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝ "
	@echo "               				2024/05/01 - ismherna@student.42.fr - 42 Madrid - Ismael Hernández      "                                                                                                                                       
                                                                                                                                             

bonus: all


#remove objects and exeutable file 
clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean