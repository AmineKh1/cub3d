NAME = cub
CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# -fsanitize=address
SRC =  cub3d.c  utils/ft_strlen.c utils/ft_strdup.c  raycast.c minimap.c
OBJ = ${SRC:.c=.o}
RM = rm -rf
MLX = -lmlx -framework OpenGL -O3 -framework Appkit
all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} ${CFLAGS} ${MLX} -o ${NAME}
%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all
.PHONY: clean all bonus fclean re