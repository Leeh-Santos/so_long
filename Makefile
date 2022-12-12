
SRCS	= main.c \
			rest/errors.c \
			rest/support.c \
			rest/support2.c \
			rest/checker.c \
			rest/checker2.c \
			rest/move.c \
			rest/move2.c \
			rest/get_next_line.c \
			rest/get_next_line_utils.c \

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

RM		= rm -rf

MLX		=	mlx_linux/libmlx_Linux.a

MLX_LIB_DIR = mlx_linux/

MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
		$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

$(MLX):
		make -C mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $^ -o $@


clean: 
	$(RM) $(OBJS)
	make clean -C mlx_linux

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re