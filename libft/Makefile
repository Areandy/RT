# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 16:13:45 by mlavreni          #+#    #+#              #
#    Updated: 2018/10/25 16:14:05 by mlavreni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
# FILES=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_get_word_len.c ft_count_words.c ft_sqr.c ft_is_upper.c ft_is_lower.c
RAW_FILES	= $(shell find . -type f | grep -E "\.c$$")
FILES		= $(RAW_FILES)
OBJ		= $(addprefix $(OBJ_DIR), $(FILES:./%.c=%.o))
# OBJ = $(FILES:.c=.o)
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

# directories
OBJ_DIR		= ./obj/

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c 
	@$(CC) $(FLAGS) -I ./ -o $@ -c $<
	@echo "(+) $@"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GRN)Libft created!$(EOC)"

clean:
	@rm -f $(OBJ)
	@rm -dfr $(OBJ_DIR)
	@echo "$(GRN)Libft is clean$(EOC)"
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

RED = \033[1;31m
GRN = \033[1;32m
YLW = \033[1;33m
INV = \033[7m
EOC = \033[0m