NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=thread
# LDFLAGS = -fsanitize=thread

SRCS		=	ft_arg_atoi.c	monitor.c	parse_input.c	philo.c	\
				philos_routine.c	set_data.c	set_table.c	\
				threads_handle.c	time_handler.c	allocation_management.c \
				destroying_mtx.c	set_forks.c 

OBJS	=		${SRCS:.c=.o}

all: $(NAME)

%.o:%.c philo.h
	@$(CC) ${CFLAGS} -c $< -o $@

$(NAME): 		${OBJS}
	@$(CC) ${LDFLAGS} ${OBJS} -o ${NAME}
	@echo "\x1b[32mfinished";

clean:
	@rm -f ${OBJS}
	@echo "\x1b[31mremoved files";

fclean: 	clean
	@rm -f $(NAME)
	@echo "\x1b[31mremoved philo";

re:		fclean all

.PHONY: clean