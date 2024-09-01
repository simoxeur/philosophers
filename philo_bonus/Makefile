NAME	= philo_bonus

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread #-g -fsanitize=thread
# LDFLAGS = -fsanitize=thread

SRCS		=	philo_bonus.c	parse_input_b.c	ft_arg_atoi_b.c	allocation_management_b.c \
				set_data_b.c	set_table_b.c	process_handle.c  philos_routine_b.c	time_handler_b.c \
				threads_handle_b.c	check_dead.c


OBJS	=		${SRCS:.c=.o}

all: $(NAME)

%.o:%.c philo_bonus.h
	@$(CC) ${CFLAGS} -c $< -o $@

$(NAME): 		${OBJS}
	@$(CC) ${LDFLAGS} ${OBJS} -o ${NAME}
	@echo "\x1b[32mfinished";

clean:
	@rm -f ${OBJS}
	@echo "\x1b[31mremoved files";

fclean: 	clean
	@rm -f $(NAME)
	@echo "\x1b[31mremoved philo_bonus";

re:		fclean all

.PHONY: clean