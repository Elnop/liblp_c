NAME = liblp.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

AR = ar rcT

LIBS_NAMES = liblp_char \
		liblp_mem \
		liblp_print \
		liblp_str \
		liblp_array \
		liblp_dico \

LIBS = $(foreach LIB_NAME, $(LIBS_NAMES), $(LIB_NAME)/$(LIB_NAME).a)

${NAME}: ${LIBS}
	${AR} $@ $^

all: ${NAME}

clean: fclean_libs

fclean: clean
	rm -f ${NAME}

re: fclean all

$(foreach LIB_NAME, $(LIBS_NAMES), $(LIB_NAME)/$(LIB_NAME).a):
	make -C $(dir $@)

fclean_libs:
	$(foreach LIB_NAME, $(LIBS_NAMES), make fclean -C $(LIB_NAME) ;)

.PHONY: all clean fclean re