NAME = cub3D
CC = cc
# CFLAGS = -fsanitize=address -g3
SRC =  cub3d.c raycast.c raycast2.c minimap.c update_map.c parsing/get_next_line.c parsing/parser.c parsing/parser_color.c parsing/parser_map.c parsing/parser_texture.c parsing/utils.c parsing/verify_file.c parsing/utils1.c
OBJ = ${SRC:.c=.o}
RM = rm -rf
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
MLX = -lmlx -framework OpenGL -O3 -framework Appkit

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${OBJ} $(LIBFT) ${CFLAGS} ${MLX} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_PATH}

clean:
	@${RM} ${OBJ}
	make clean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME}
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: clean all bonus fclean re