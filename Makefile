# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 18:38:45 by kdhrif            #+#    #+#              #
#    Updated: 2023/01/14 15:26:53 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     = philosophers
BONUS_NAME = philosophers_bonus
SRCS_DIR = srcs
BONUS_DIR = bonus
OBJS_DIR = objs
BONUS_OBJS_DIR = bonus_objs
SRCS	:= $(shell find srcs/*.c -exec basename \ {} \;)
BONUS	:= $(shell find bonus/*.c -exec basename \ {} \;)
OBJS     = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS}}
BONUS_OBJS = ${patsubst %.c,${BONUS_OBJS_DIR}/%.o,${BONUS}}
CC       = gcc
CFLAGS   = -g3 -Wall -Wextra -Werror
HEADERS  = includes/philosophers.h
BONUS_HEADERS = includes/philosophers_bonus.h

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "\033[33mcompiling ${NAME}..."
	@echo "SRCS = ${SRCS}"
	@echo "OBJS = ${OBJS}"

$(BONUS_OBJS_DIR):
	@mkdir -p $(BONUS_OBJS_DIR)
	@echo "\033[33mcompiling ${NAME}..."
	@echo "SRCS = ${BONUS}"
	@echo "OBJS = ${BONUS_OBJS}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -c $< -o $@


${NAME}: $(OBJS_DIR) $(OBJS) ${HEADERS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m$ ${NAME} compiled !"

${BONUS_OBJS_DIR}/%.o: ${BONUS_DIR}/%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BONUS_NAME}: $(BONUS_OBJS_DIR) $(BONUS_OBJS) ${BONUS_HEADERS}
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "\033[32m$ ${NAME} compiled !"

bonus: ${BONUS_NAME}

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(BONUS_OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
