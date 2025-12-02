NAME	= fract-ol
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# Directories
LIBFT_DIR	= src/utils/libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= minilibX

# Source files
SRCS	= src/main.c \
		  src/mandelbrot.c \
		  src/julia.c \
		  src/utils/operations.c \
		  src/utils/utilsa.c \
		  src/utils/utils_maths.c \
		  src/utils/minilibx_utils.c \
		  src/utils/events.c \
		  src/utils/render.c \
		  src/utils/errors_handle.c \
		  src/utils/libft/ft_printf/ft_printf.c \
		  src/utils/libft/ft_printf/ft_printf_utils.c \

# Object files (replaces src/ with obj/ and .c with .o)
OBJS	= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	@echo "$(NAME) compiled successfully!"

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Pattern rule: compiles any .c file in src/ to .o file in obj/
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) obj
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
