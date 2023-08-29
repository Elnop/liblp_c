ARRAY_SRCS_DIR = array/src

ARRAY_OBJS_DIR = .build

ARRAY_FILES = test_array_create \
			test_array_grow \
			test_array_pushback_tab \
			test_array_remove

ARRAY_SRCS = $(addprefix $(ARRAY_SRCS_DIR)/, $(addsuffix .c, $(ARRAY_FILES)))

ARRAY_OBJS = $(addprefix $(ARRAY_OBJS_DIR)/, $(addsuffix .o, $(ARRAY_FILES)))

$(ARRAY_OBJS_DIR)/%.o: $(ARRAY_SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@