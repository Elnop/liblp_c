NAME = liblp_mem.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES = lp_bzero \
		lp_calloc \
		lp_memchr \
		lp_memcmp \
		lp_memcpy \
		lp_memmove \
		lp_memset \
		lp_memswap \
		lp_realloc

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = obj
OBJS = ${patsubst ${SRCS_DIR}/%.c, ${OBJS_DIR}/%.o, ${SRCS}}

$(NAME): $(OBJS)
	$(AR) $@ $^

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re make_dirs