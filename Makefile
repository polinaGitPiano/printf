# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eidaho <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 14:51:15 by eidaho            #+#    #+#              #
#    Updated: 2020/02/04 14:51:17 by eidaho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCDIR = src/

SRC =  ft_format_str.c\


OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR), $(SRC:%.c=%.o))

INCLUDES = includes/

HEADER = $(addprefix $(INCLUDES), ft_printf.h)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
    ar rc $(NAME) $(OBJ)
    ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
    gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES)

$(OBJDIR):
    mkdir obj/

clean:
    rm -rf $(OBJ) main.o
    rm -rf $(OBJDIR)

fclean: clean
    rm -rf $(NAME)

re: fclean all