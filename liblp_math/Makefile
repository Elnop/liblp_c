NAME = liblp_math.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES = lp_abs \
		lp_fabs \
		lp_power \
		lp_int_len \
		lp_uint_len \
		lp_int_lenbase \
		lp_uint_lenbase \
		lp_ulong_lenbase \
		lp_get_timestamp \
		lp_wait \

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