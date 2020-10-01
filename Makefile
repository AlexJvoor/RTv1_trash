NAME = RTv1

# don't wanna fuck with -Werror for now
FLAGS = -c -Wall -Wextra #-Werror

### MLXFLAGS = -lmlx -framework OpenGL -framework OpenCL -framework AppKit -Wall -Wextra -Werror

SRCS = main.c \
       init_sdl.c \
       init_sdl_layers.c \
       main_loop.c \
       safe_call.c \
       test_condition.c \
       test_entry_point.c

INCLUDES = $(addprefix -I, ./includes)

# it's from Ri's makefile
SDL_DIR		=	./SDL
SDL_DIST	=	$(PWD)/SDL/dist
SDL_INCLUDE =	$(SDL_DIR)/dist/include/SDL2
SDL_LINK	=	`$(SDL_DIST)/bin/sdl2-config --cflags --libs`

detected_OS := $(shell uname)

ifeq ($(detected_OS),Linux)

	SDL_FLAGS := -lOpenCL

endif

ifeq ($(detected_OS),Darwin)

	SDL_FLAGS = -framework OpenCL

endif

HEADERS = includes/rtv1.h

LIBFT = libft/libft.a

DIR_O = objs

DIR_S = src

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SDL_DIST) $(DIR_O) $(OBJS) $(HEADERS)
	@make -C ./libft
	gcc -I includes -I $(SDL_INCLUDE) $(OBJS) $(LIBFT) -lm $(SDL_LINK) -o $(NAME)
#   priv.sh does not work anymore :<
# 	@sh /Users/hchau/Desktop/hohow/priv.sh

# it's from Rita's makefile too
$(SDL_DIST):
	$(info ************ Compiling SDL *************)
	$(info --prefix=$(SDL_DIST))
	mkdir -p $(SDL_DIR)/tmp
	cd $(SDL_DIR)/tmp; ../configure --prefix=$(SDL_DIST)
	make -C $(SDL_DIR)/tmp
	make -C $(SDL_DIR)/tmp install > /dev/null
	$(info SDL_LINK: $(SDL_LINK))

$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean --directory ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean --directory ./libft
	rm -rf $(SDL_DIST)

re: fclean all

.PHONY: all dir clean fclean re