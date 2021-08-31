# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 12:24:26 by gesperan          #+#    #+#              #
#    Updated: 2021/05/28 16:19:07 by gesperan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIBFTDIR=	libft/
LIBFT	=	${LIBFTDIR}libft.a
HEADERS	=	libft/libft.h
FUNCS	=	checks.c checkk.c comands.c comandsthree.c comandstwo.c operations.c \
			errors.c operationstwo.c firststep.c fivenum.c thirdstage.c
OBJS	=	${FUNCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm
MAKES	=	makes
all: ${MAKES} ${NAME}
${NAME}: ${OBJS} ${HEADERS} ${LIBFT} Makefile
	${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}
${MAKES}:
	@${MAKE} -sC ${LIBFTDIR}
%.o : %.c ${HEADERS}
	${CC} -c ${CFLAGS} ${INCL} $< -o $@
${LIBFT}:
	@${MAKE} -sC ${LIBFTDIR}
clean:
	@${MAKE} -sC ${LIBFTDIR} clean
	${RM} -f ${OBJS}
fclean: clean
	@${MAKE} -sC ${LIBFTDIR} fclean
	${RM} -f ${NAME}
re:	fclean all
.PHONY: all clean fclean re
