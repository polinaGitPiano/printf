NAME =	libftprintf.a

SRC1 =	./libft/ft_atoi.c\
				./libft/ft_bzero.c\
				./libft/ft_count_if.c\
				./libft/ft_div_mod.c\
				./libft/ft_floor.c\
				./libft/ft_foreach.c\
				./libft/ft_isalnum.c\
				./libft/ft_isalpha.c\
				./libft/ft_isascii.c\
				./libft/ft_isdigit.c\
				./libft/ft_isprint.c\
				./libft/ft_itoa.c\
				./libft/ft_lstadd.c\
				./libft/ft_lstdel.c\
				./libft/ft_lstdelone.c\
				./libft/ft_lstiter.c\
				./libft/ft_lstmap.c\
				./libft/ft_lstnew.c\
				./libft/ft_memalloc.c\
				./libft/ft_memccpy.c\
				./libft/ft_memchr.c\
				./libft/ft_memcmp.c\
				./libft/ft_memcpy.c\
				./libft/ft_memdel.c\
				./libft/ft_memmove.c\
				./libft/ft_memset.c\
				./libft/ft_putchar.c\
				./libft/ft_puthar_fd.c\
				./libft/ft_putendl.c\
				./libft/ft_putendl_fd.c\
				./libft/ft_putnbr.c\
				./libft/ft_putnbr_fd.c\
				./libft/ft_putstr.c\
				./libft/ft_putstr_fd.c\
				./libft/ft_sqrt.c\
				./libft/ft_strcat.c\
				./libft/ft_strchr.c\
				./libft/ft_strclr.c\
				./libft/ft_strcmp.c\
				./libft/ft_strcpy.c\
				./libft/ft_strdel.c\
				./libft/ft_strdup.c\
				./libft/ft_strequ.c\
				./libft/ft_striter.c\
				./libft/ft_striteri.c\
				./libft/ft_strjoin.c\
				./libft/ft_strlcat.c\
				./libft/ft_strlen.c\
				./libft/ft_strmap.c\
				./libft/ft_strmapi.c\
				./libft/ft_strncat.c\
				./libft/ft_strncmp.c\
				./libft/ft_strncpy.c\
				./libft/ft_strnequ.c\
				./libft/ft_strnew.c\
				./libft/ft_strnstr.c\
				./libft/ft_strrchr.c\
				./libft/ft_strsplit.c\
				./libft/ft_strstr.c\
				./libft/ft_strsub.c\
				./libft/ft_strtrim.c\
				./libft/ft_tolower.c\
				./libft/ft_toupper.c

SRC2 =	./src/ft_printf.c\

OBJ =	./obj/ft_atoi.o\
				./obj/ft_printf.o\
				./obj/ft_bzero.o\
				./obj/ft_count_if.o\
				./obj/ft_div_mod.o\
				./obj/ft_floor.o\
				./obj/ft_foreach.o\
				./obj/ft_isalnum.o\
				./obj/ft_isalpha.o\
				./obj/ft_isascii.o\
				./obj/ft_isdigit.o\
				./obj/ft_isprint.o\
				./obj/ft_itoa.o\
				./obj/ft_lstadd.o\
				./obj/ft_lstdel.o\
				./obj/ft_lstdelone.o\
				./obj/ft_lstiter.o\
				./obj/ft_lstmap.o\
				./obj/ft_lstnew.o\
				./obj/ft_memalloc.o\
				./obj/ft_memccpy.o\
				./obj/ft_memchr.o\
				./obj/ft_memcmp.o\
				./obj/ft_memcpy.o\
				./obj/ft_memdel.o\
				./obj/ft_memmove.o\
				./obj/ft_memset.o\
				./obj/ft_putchar.o\
				./obj/ft_puthar_fd.o\
				./obj/ft_putendl.o\
				./obj/ft_putendl_fd.o\
				./obj/ft_putnbr.o\
				./obj/ft_putnbr_fd.o\
				./obj/ft_putstr.o\
				./obj/ft_putstr_fd.o\
				./obj/ft_sqrt.o\
				./obj/ft_strcat.o\
				./obj/ft_strchr.o\
				./obj/ft_strclr.o\
				./obj/ft_strcmp.o\
				./obj/ft_strcpy.o\
				./obj/ft_strdel.o\
				./obj/ft_strdup.o\
				./obj/ft_strequ.o\
				./obj/ft_striter.o\
				./obj/ft_striteri.o\
				./obj/ft_strjoin.o\
				./obj/ft_strlcat.o\
				./obj/ft_strlen.o\
				./obj/ft_strmap.o\
				./obj/ft_strmapi.o\
				./obj/ft_strncat.o\
				./obj/ft_strncmp.o\
				./obj/ft_strncpy.o\
				./obj/ft_strnequ.o\
				./obj/ft_strnew.o\
				./obj/ft_strnstr.o\
				./obj/ft_strrchr.o\
				./obj/ft_strsplit.o\
				./obj/ft_strstr.o\
				./obj/ft_strsub.o\
				./obj/ft_strtrim.o\
				./obj/ft_tolower.o\
				./obj/ft_toupper.o

FLAG = -Wall -Werror -Wextra

OBJECT = obj
CC = gcc

all : $(NAME)

$(NAME) :
		@mkdir $(OBJECT)
		@$(CC) -c $(SRC1) $(FLAG) 
		@$(CC) -c $(SRC2) $(FLAG)
		@mv *.o ./obj
		@ar rc $(NAME) $(OBJ)
		@echo "\x1b[32m---------- COMPILED SUCCESSFULLY ----------\x1b[0m"

clean :
		@rm -fr obj
		@rm -f ft_printf
		@echo "\x1b[32m---------- CLEANED SUCCESSFULLY ----------\x1b[0m"

fclean : clean
		@rm -rf $(NAME)

test : all
		@$(CC) ./src/main.c libftprintf.a -I includes/ft_printf.h -o ft_printf
		@echo "\x1b[32m---------- TEST COMPILED SUCCESSFULLY ----------\x1b[0m"

re : fclean all