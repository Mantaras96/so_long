CFLAGS 	= -Wall -Wextra -Werror

SRCS	=	src/main.c \
		src/validate_and_read_map.c \
		src/validate_letters_map.c \
		src/show_map.c \
		src/error.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c

OBJS 	= ${SRCS:.c=.o}

OBJS_B 	= ${SRCS_B:.c=.o}

NAME 	= so_long.a

RM 		= rm -f

.c.o:	
	make -C libft
	make -C mlx
	gcc -c ${CFLAGS} -Imlx $< -o ${<:.c=.o}

all:		$(NAME)

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			gcc ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a ${NAME} -o so_long

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."
			make clean -C mlx

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."
			make clean -C mlx

re:			fclean all

.PHONY:		all clean fclean re