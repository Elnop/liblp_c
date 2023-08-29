include base.mk
include array/test_array.mk

FILES = main

SRCS = $(addsuffix .c, $(FILES))

OBJS_DIR = .build

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES))) \
		$(ARRAY_OBJS)

LIBLP_DIR = ..

LIBLP = $(LIBLP_DIR)/liblp_c.a

$(NAME): $(LIBLP) $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) $(LIBLP) -o $(NAME)

$(LIBLP):
	make -C ${LIBLP_DIR}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean: cleanlibs
	rm -rf $(OBJS_DIR)

cleanlibs:
	make fclean -C ${LIBLP_DIR}

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re cleanlibs