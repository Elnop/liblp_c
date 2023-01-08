NAME = liblp_print.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES = lp_putchar_fd \
		lp_putchar_fdpc \
		lp_putendl_fd \
		lp_putendl_fdpc \
		lp_putnbr_fd \
		lp_putnbr_fdpc \
		lp_putstr_fd \
		lp_putstr_fdpc \

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
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re