NAME = fractol

SRC = fractol.c equations.c utils.c hooks.c

OBJ =	${SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX_PATH = ./minilibx_opengl_20191021

MLX = libmlx.a

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(MLX_PATH) -c $< -o $@

all:	$(OBJ) $(MLX) $(NAME)

$(MLX):
			make -C $(MLX_PATH)

$(NAME):	$(OBJ)
			$(CC) -Ofast $(OBJ) -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)
			make -C $(MLX_PATH) clean

fclean:		clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re