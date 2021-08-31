
NAME = 				libft.a

FLAGS = 			-c -Wall -Wextra -Werror

LIBFT = 		ft_atoi.c  ft_bzero.c  ft_substr.c ft_putchar_fd.c \
				ft_calloc.c ft_strlen.c ft_split.c ft_isdigit.c \
				ft_memory_free.c ft_size_arr.c  ft_ps_cub.c ft_putstr_fd.c

OBJ =			$(LIBFT:.c=.o)

HEADERS =		 libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	ar rc $(NAME) $(OBJ) $(HEADERS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	gcc $(FLAGS) $< -o $@

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f libft.a

re: fclean all
