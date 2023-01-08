NAME = liblp.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

AR = ar rcT

LIBS = liblp_char/liblp_char.a \
		liblp_mem/liblp_mem.a \
		liblp_print/liblp_print.a \
		liblp_str/liblp_str.a \
		liblp_array/liblp_array.a \
		liblp_dico/liblp_dico.a \

${NAME}: ${LIBS}
	${AR} $@ $^

all: ${NAME}

clean: fclean_libs

fclean: clean
	rm -f ${NAME}

re: fclean all

${LIBS}: char_make mem_make print_make str_make array_make dico_make

fclean_libs: char_fclean mem_fclean print_fclean str_fclean array_fclean dico_fclean

array_make:
	make -C liblp_array

array_fclean:
	make fclean -C liblp_array

dico_make:
	make -C liblp_dico

dico_fclean:
	make fclean -C liblp_dico

char_make:
	make -C liblp_char

char_fclean:
	make fclean -C liblp_char

mem_make:
	make -C liblp_mem

mem_fclean:
	make fclean -C liblp_mem

print_make:
	make -C liblp_print

print_fclean:
	make fclean -C liblp_print

str_make:
	make -C liblp_str

str_fclean:
	make fclean -C liblp_str

.PHONY: all clean fclean re