NAME = liblp_dico.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

AR = ar rcs

FILES = lp_dico_create \
		lp_dico_get \
		lp_dico_has \
		lp_dico_set \
		lp_dico_foreach \
		lp_dico_set_many \
		lp_dico_delete \

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