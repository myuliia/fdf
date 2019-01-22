#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 15:27:07 by myuliia           #+#    #+#              #
#    Updated: 2019/01/16 14:54:51 by myuliia          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./read.c \
      ./main.c \
      ./valid.c \
      ./error.c \
      ./key_hooks.c \
      ./draw.c \
      ./changes.c \
      ./draw_line.c \
      ./titles.c \

OBJ = $(SRC: .c=.o)

HEADER = fdf.h

FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a

%.o: %.c $(HEADER)
		gcc -c -o $@ $<

clean:
		@rm -f *.o

fclean: clean
		@rm -f $(NAME)

re: fclean all