# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 16:43:26 by oalsadi-          #+#    #+#              #
#    Updated: 2024/09/13 12:46:55 by ismherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar -rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a 
SRC = ft_tolower.c ft_putstr_fd.c ft_putendl_fd.c ft_isalnum.c ft_isalpha.c \
ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_strncmp.c ft_strnstr.c \
ft_putchar_fd.c ft_putnbr_fd.c ft_strjoin.c ft_calloc.c ft_strdup.c ft_memchr.c ft_memcmp.c ft_substr.c ft_itoa.c \
ft_split.c ft_strrchr.c ft_strmapi.c ft_striteri.c ft_atoi.c ft_strchr.c ft_strtrim.c \
ft_printf.c	ft_printf_str.c	ft_printf_unsigned.c ft_printf_num.c ft_printf_hexa.c ft_printf_char.c ft_printf_pointers.c
OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE) 
	$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJBONUS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJBONUS) $(OBJ)


%.o: %.c $(INCLUDE) 	
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re 

clean:	
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus
