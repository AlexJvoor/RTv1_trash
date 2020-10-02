NAME = RTv1

FLAGS = -c -Wall -Wextra -Werror

### MLXFLAGS = -lmlx -framework OpenGL -framework OpenCL -framework AppKit -Wall -Wextra -Werror

SRCS = main.c \

INCLUDES = $(addprefix -I, ./includes)

HEADERS = includes/rtv1.h

LIBFT = libft/libft.a

DIR_O = objs

DIR_S = src

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS) $(HEADERS)
	@make -C ./libft
	gcc -I includes $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -rf $(DIR_O)
	@make fclean -C ./libft
	@make fclean -C ./libnum

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all dir clean fclean re