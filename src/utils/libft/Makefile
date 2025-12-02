# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 10:06:26 by jmiguele          #+#    #+#              #
#    Updated: 2025/10/09 11:17:45 by jmiguele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf


SRCS =  ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memset.c \
        ft_bzero.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c \
        ft_putchar_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_putstr_fd.c \

BSRCS = ft_lstnew_bonus.c \
        ft_lstadd_front_bonus.c \
        ft_lstsize_bonus.c \
        ft_lstlast_bonus.c \
        ft_lstadd_back_bonus.c \
        ft_lstdelone_bonus.c \
        ft_lstclear_bonus.c \
        ft_lstiter_bonus.c \
        ft_lstmap_bonus.c \

PRINTF_SRCS = ft_printf/ft_printf.c \
              ft_printf/ft_printf_utils.c \

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: bonus

$(NAME): $(OBJS) $(PRINTF_OBJS)
	@echo "Compilando librería..."
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(PRINTF_OBJS)
	@echo "Libreria creada: $(NAME)"

bonus: $(NAME) $(BOBJS)
	@echo "Compilando bonus..."
	@$(AR) $(ARFLAGS) $(NAME) $(BOBJS)

%.o: %.c
	@echo "Compilando"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJS) $(BOBJS) $(PRINTF_OBJS)

fclean: clean
	@echo "Eliminando libreria..."
	@$(RM) $(NAME)
	@echo "Libreria $(NAME) eliminada."

re: fclean all

.PHONY: all clean fclean re bonus
