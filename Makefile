########################### VARIABLES ###########################

# Colors ----------------------------------------------------- #
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
CIAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m

# Final program ---------------------------------------------- #
NAME = so_long

# Source files ----------------------------------------------- #
SRCS = $(SRC_FILES) $(SRC_GNL_FILES)

SRC_DIR = src
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC_CFILES))
SRC_CFILES =	main.c \
				read_map.c \
				parse_map_1.c \
				parse_map_2.c \
				graphic_functions.c \
				key_controls.c \
				error_management.c \
				init_data_structure.c \
				utils_for_testing_1.c \
				utils_for_testing_2.c 

SRC_GNL_DIR = $(SRC_DIR)/gnl
SRC_GNL_FILES = $(addprefix $(SRC_GNL_DIR)/, $(SRC_GNL_CFILES))
SRC_GNL_CFILES = 	get_next_line.c \
					get_next_line_utils.c \

# Source/linker files ---------------------------------------- #
LIBFT_DIR =$(SRC_DIR)/libft
PRINTF_DIR =$(SRC_DIR)/ft_printf
MLX_DIR = mlx

# Object files ----------------------------------------------- #
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

OBJ_DIR = obj
OBJ_GNL_DIR = $(OBJ_DIR)/gnl

# Include files (header) ------------------------------------- #
INCL_DIR = includes

# Compiler options ------------------------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror  $(SANITIZE)
LINKFLAGS = -L./$(LIBFT_DIR) -lft -L./$(PRINTF_DIR) -lftprintf -L./$(MLX_DIR) -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit

SANITIZE=
# SANITIZE=-g -fsanitize=address

########################## RULES ###############################

all: $(NAME)


$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(LINKFLAGS) $(FRAMEWORKS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)[+] $(NAME) compilado$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(OBJ_GNL_DIR)
	@$(CC) $(CFLAGS) -I./$(INCL_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_GNL_DIR):
	@mkdir -p $(OBJ_GNL_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)[+] Archivos objeto .o borrados$(END)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(MAKE) fclean -C $(MLX_DIR)
	@rm -f $(NAME)
	@echo "$(MAGENTA)[+] $(NAME) borrado $(END)"

re: fclean all

.PHONY: all clean fclean re
