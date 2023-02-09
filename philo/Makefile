# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 18:38:45 by kdhrif            #+#    #+#              #
#    Updated: 2023/02/09 18:56:04 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     = philo
SRCS_DIR = srcs
BONUS_DIR = bonus
OBJS_DIR = objs
# SRCS	:= $(shell find srcs/*.c -exec basename \ {} \;)
SRCS := srcs/error.c srcs/forks.c srcs/ft_atoi.c srcs/glossy_if.c srcs/handle_only_one.c srcs/init_philo.c srcs/life.c srcs/log.c srcs/meal_update.c srcs/memory.c srcs/mutex.c srcs/parsing.c srcs/philo.c srcs/philosophers.c srcs/protected_vars.c srcs/silent_kill.c srcs/singleton.c srcs/threads.c srcs/time.c 
# OBJS     = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS}}
OBJS := objs/error.o objs/forks.o objs/ft_atoi.o objs/glossy_if.o objs/handle_only_one.o objs/init_philo.o objs/life.o objs/log.o objs/meal_update.o objs/memory.o objs/mutex.o objs/parsing.o objs/philo.o objs/philosophers.o objs/protected_vars.o objs/silent_kill.o objs/singleton.o objs/threads.o objs/time.o
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
HEADERS  = includes/philosophers.h

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "\033[33mcompiling ${NAME}..."
	@echo "SRCS = ${SRCS}"
	@echo "OBJS = ${OBJS}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -pthread -c $< -o $@


${NAME}: $(OBJS_DIR) $(OBJS) ${HEADERS}
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)
	@echo "\033[32m$ ${NAME} compiled !"

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
