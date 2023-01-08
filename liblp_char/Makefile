NAME = liblp_char.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES = lp_isalnum \
		lp_isalpha \
		lp_isascii \
		lp_isdigit \
		lp_tolower \
		lp_toupper \
		lp_isprint \

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = obj
OBJS = ${patsubst ${SRCS_DIR}/%.c, ${OBJS_DIR}/%.o, ${SRCS}}

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

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