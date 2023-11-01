# --- VARIABLES --- #

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
SRCS_DIR = ./
SRCS = main.cpp
OBJ_DIR = objs/
OBJ = ${SRCS:%.cpp=${OBJ_DIR}%.o}
NAME = brain
RM = rm -f
HEADERS = 

# --- COLORS --- #

_NOC	:=	\033[0m
_RED	:=	\033[1;31m
_GREEN	:=	\033[1;32m

# --- RULES --- #

${NAME} :	${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${OBJ}: ${OBJ_DIR}%.o :	${SRCS_DIR}%.cpp ${HEADERS} 
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -c $< -o $@

all :	${NAME}

clean :
		rm -rf objs/
		@echo "${_RED}### Removed ${NAME} object files ###${_NOC}"

fclean :	clean
		${RM} ${NAME}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re