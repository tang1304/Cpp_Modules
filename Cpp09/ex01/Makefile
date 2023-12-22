# --- VARIABLES --- #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3# -fsanitize=address
SRCS_DIR = ./srcs/
SRCS = RPN.cpp main.cpp
OBJ_DIR = objs/
OBJ = ${SRCS:%.cpp=${OBJ_DIR}%.o}
NAME = RPN
RM = rm -f
HEADERS_DIR = ./incs/
HEADERS_FILES = RPN.hpp
HEADERS = $(addprefix ${HEADERS_DIR}/, ${HEADERS_FILES})

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
		${CC} ${CFLAGS} -I/usr/include -I ${HEADERS_DIR} -c $< -o $@

all :	${NAME}

clean :
		rm -rf objs/
		@echo "${_RED}### Removed ${NAME} object files ###${_NOC}"

fclean :	clean
		${RM} ${NAME}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean
	${MAKE} all

.PHONY : all clean fclean re