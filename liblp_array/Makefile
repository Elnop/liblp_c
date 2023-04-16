NAME = liblp_array.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

AR = ar rcs

FILES = strtab_to_intarray \
		array_size \
		array_dup \
		array_new \
		array_pushfront \
		array_remove \
		array_header \
		array_elemsize \
		array_set_size \
		array_free \
		array_get \
		array_reverse \
		array_int_print \
		array_rotate \
		array_capacity \
		array_issort \
		array_sort \
		array_swap \
		array_indexof \
		array_has \
		array_foreach \
		array_grow \
		array_pushback_tab \
		array_pushback \
		array_pushfront_tab \
		str_to_array

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