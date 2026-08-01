NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
MLX_DIR = MLX42
MLX_BUILD = $(MLX_DIR)/build
MLX_LIB = $(MLX_BUILD)/libmlx42.a

SRC = main.c arguments.c atod.c init.c render.c iterations.c color.c \
	events.c loop.c utils.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDES = -I$(INC_DIR) -I$(MLX_DIR)/include
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
GLFW_DIR := $(shell brew --prefix glfw 2>/dev/null)
ifneq ($(GLFW_DIR),)
GLFW_FLAGS = -L$(GLFW_DIR)/lib -lglfw
else
GLFW_FLAGS = -lglfw
endif
LIBS = $(MLX_LIB) $(GLFW_FLAGS) -framework Cocoa -framework OpenGL \
	-framework IOKit -lm
else
LIBS = $(MLX_LIB) -ldl -lglfw -pthread -lm
endif

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(MLX_LIB):
	cmake -S $(MLX_DIR) -B $(MLX_BUILD)
	cmake --build $(MLX_BUILD) -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX_BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
