# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 15:50:18 by obouhrir          #+#    #+#              #
#    Updated: 2023/06/14 20:22:26 by obouhrir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#varibales
# -g
NAME   = philo
CC	   = cc 
CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread -g
SRC    = philo.c utl.c alloc_dest.c main.c routine.c simulation.c simulation1.c

#colours
GREEN = "\033[32m"
GREY = "\033[30m"
CYAN = "\033[36m"
RED = "\033[31m"

all : ${NAME} 

${NAME} : ${SRC} philo.h
	@echo ${GREEN}"Compiling ${NAME}..."
	@${CC} ${CFLAGS}  ${SRC} -o ${NAME}
	@echo "Successfully compiled ${NAME}!"

clean :
	@echo ${GREY}"Cleaning up..."
	@echo there are no objects files

fclean : clean
	@echo ${RED}"Removing ${NAME}..."
	@rm -f ${NAME}

re : fclean all