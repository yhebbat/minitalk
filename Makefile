NAME = server client

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror server.c -o server
	@gcc -Wall -Wextra -Werror client.c -o client
	@echo "✅🤖✅"
clean:
	@rm -f $(NAME)
	@echo "🚮🚮🚮"
fclean: clean
re: clean all