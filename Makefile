OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

libft:
	make -C libft

clean:
	make -C libft clean
	
fclean: clean
	rm -f libft/libft.a

re: fclean all

git:
  git add .
  git commit -m "Automatic commit fron makefile"
  git push

.PHONY: all bonus libft clean fclean re
