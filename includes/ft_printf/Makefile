NAME	=	libftprintf.a
INCLUDE	= 	ft_pintf.h

SRC		=	ft_printf.c					\
			ft_printf_str.c				\
			ft_printf_unsigned.c		\
			ft_printf_num.c				\
			ft_printf_hexa.c			\
			ft_printf_char.c			\
			ft_printf_pointers.c

OBJ		=	${SRC:.c=.o}

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

CFLAGS  = 	-Wall -Wextra -Werror

DEF_COLOR   =   \033[0;39m
GRAY        =   \033[0;90m
RED         =   \033[0;91m
GREEN       =   \033[0;92m
YELLOW      =   \033[0;93m
BLUE        =   \033[0;94m
MAGENTA     =   \033[0;95m
CYAN        =   \033[0;96m
WHITE       =   \033[0;97m

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

$(NAME): ${OBJ}
	@echo "compilando .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "printf compilado!!"

clean:
	@echo "$(RED)eliminando .o  ...$(DEF_COLOR)"
	${RM} ${OBJ}
	@echo "$(BLUE)Objetos eliminados: $(words ${OBJ})  ${OBJ}$(DEF_COLOR)"
	@echo "$(GREEN)Hecho !"

fclean: clean
	@echo "$(RED)eliminando libftprintf.a ...$(DEF_COLOR)"	
	${RM} $(NAME)
	@echo "$(BLUE)Objetos eliminados:  $(words $(NAME))  $(NAME)$(DEF_COLOR)"
	@echo "$(GREEN)Hecho !$(DEF_COLOR)"

re: fclean all  