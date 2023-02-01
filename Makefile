NAME = fract-ol

SRC = fract-ol.c equations.c

OBJ =	${SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX_PATH = ./minilibx_opengl_20191021

MLX = libmlx.a

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(MLX_PATH) -c $< -o $@

all:	$(NAME)

$(MLX):		$(OBJ)
			make -C $(MLX_PATH)

$(NAME):	$(MLX) $(OBJ)
			$(CC) $(CCFLAGS) $(OBJ) -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

clean:		$(OBJ)
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make -C $(MLX_PATH) clean
			$(RM) $(MLX)

re: fclean all

.PHONY: all clean fclean re