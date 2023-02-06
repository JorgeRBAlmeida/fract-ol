NAME = fractol

NAME_BONUS = fractol_bonus

SRC = fractol.c equations.c utils.c events.c render.c

SRC_BONUS = fractol_bonus.c equations_bonus.c utils_bonus.c events_bonus.c render_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX_PATH = ./minilibx_opengl_20191021

MLX = libmlx.a

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) ${CCFLAGS} -I$(MLX_PATH) -c $< -o $@

all:	$(OBJ) $(MLX) $(NAME)

$(MLX):
			@make -C $(MLX_PATH)

$(NAME):	$(OBJ)
			$(CC) -Ofast $(OBJ) -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

bonus: $(NAME_BONUS) 

$(NAME_BONUS):	$(OBJ_BONUS) $(MLX)
				$(CC) -Ofast $(OBJ_BONUS) -L$(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)
			$(RM) $(OBJ_BONUS)
			make -C $(MLX_PATH) clean

fclean:		clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus