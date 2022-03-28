NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./include -I ./libft
LIB			=	-L ./libft -lft
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/main.c \
				src/validate_and_read_map.c \
				src/validate_letters_map.c \
				src/show_map.c \
				src/error.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c

all:		$(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS)  -fsanitize=address -o $@ $^ $(LIB)

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re