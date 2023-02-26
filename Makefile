NAME = cub3d
CC = cc
CFLAGS =  -fsanitize=address
SRC =  cub3d.c raycast.c minimap.c get_next_line.c parser.c parser_color.c parser_map.c parser_texture.c utils.c  verify_file.c
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