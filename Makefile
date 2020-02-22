# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eidaho <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 20:45:52 by eidaho            #+#    #+#              #
#    Updated: 2020/02/22 20:45:56 by eidaho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCDIRECTORIA = src/
SRC = 

OBJDIRECTORIA = obj/
OBJ = $(addprefix &(OBJDERICTORIA), $(SRC:%.c=%.o))

