# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 18:38:45 by kdhrif            #+#    #+#              #
#    Updated: 2023/02/03 16:09:47 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BONUS_NAME = philo_bonus
BONUS_DIR = bonus
BONUS_OBJS_DIR = bonus_objs
BONUS	:= $(shell find bonus/*.c -exec basename \ {} \;)
BONUS_OBJS = ${patsubst %.c,${BONUS_OBJS_DIR}/%.o,${BONUS}}
CC       = gcc
CFLAGS   = -g3 -Wall -Wextra -Werror
HEADERS  = includes/philosophers.h
BONUS_HEADERS = includes/philosophers_bonus.h

all: $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	@mkdir -p $(BONUS_OBJS_DIR)
	@echo "\033[33mcompiling ${NAME}..."
	@echo "SRCS = ${BONUS}"
	@echo "OBJS = ${BONUS_OBJS}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -pthread -c $< -o $@

${BONUS_OBJS_DIR}/%.o: ${BONUS_DIR}/%.c
	@${CC} ${CFLAGS} -pthread  -c $< -o $@

${BONUS_NAME}: $(BONUS_OBJS_DIR) $(BONUS_OBJS) ${BONUS_HEADERS}
	$(CC) $(CFLAGS) -pthread  $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "\033[32m$ ${NAME} compiled !"

clean:
	rm -rf $(BONUS_OBJS_DIR)

fclean: clean
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
