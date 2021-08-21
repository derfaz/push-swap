HEADERS_DIR			=	./headers
LIB_DIR				=	./libft_files
PUSH_DIR			=	./push_files

SRCS_lib		=	${LIB_DIR}/ft_atoi.c \
				${LIB_DIR}/ft_strncmp.c \
				${LIB_DIR}/ft_strjoin.c \
				${LIB_DIR}/ft_strjoin_free.c \
				${LIB_DIR}/ft_strlen.c \
				${LIB_DIR}/ft_strchr.c \
				${LIB_DIR}/ft_strnstr.c \
				${LIB_DIR}/ft_memmove.c \
				${LIB_DIR}/ft_memcpy.c \
				${LIB_DIR}/ft_memdel.c

SRCS_push		=	${PUSH_DIR}/add_chunk1.c \
				${PUSH_DIR}/add_chunk2.c \
				${PUSH_DIR}/check_chunk.c \
				${PUSH_DIR}/check_rr.c \
				${PUSH_DIR}/chunk_sort.c \
				${PUSH_DIR}/commands.c \
				${PUSH_DIR}/list_operations1.c \
				${PUSH_DIR}/list_operations2.c \
				${PUSH_DIR}/list_operations3.c \
				${PUSH_DIR}/main.c \
				${PUSH_DIR}/malloc_chunk.c \
				${PUSH_DIR}/min_max.c \
				${PUSH_DIR}/move_half.c \
				${PUSH_DIR}/move_half_rr.c \
				${PUSH_DIR}/sorting1.c \
				${PUSH_DIR}/sorting2.c \
				${PUSH_DIR}/text.c \


HEADER_lib		=	${HEADERS_DIR}/libft.h
HEADER_push		=	${HEADERS_DIR}/push.h

OBJS_lib		=	${SRCS_lib:.c=.o}
OBJS_push		=	${SRCS_push:.c=.o}

NAME		=	 push_swap

.c.o:
			cc -c $< -o ${<:.c=.o} -I ${HEADERS_DIR}


${NAME}:	${OBJS_lib} ${OBJS_push}
			gcc -o ${NAME} ${OBJS_lib} ${OBJS_push}

${OBJS_lib}:	${HEADER_lib}
${OBJS_push}:	${HEADER_push} ${OBJS_lib}

.PHONY:		clean fclean all re

all:		${NAME}

clean:
		rm -f ${OBJS_push} ${OBJS_lib}


fclean:		clean
		rm -f ${NAME}

re:		fclean all
