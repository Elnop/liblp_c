NAME = liblp_str.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES = lp_atoi \
		lp_atol \
		lp_itoa \
		lp_split \
		lp_strchr \
		lp_strdup \
		lp_striteri \
		lp_strjoin \
		lp_strlcat \
		lp_strlcpy \
		lp_strlen \
		lp_strmapi \
		lp_strncmp \
		lp_substr \
		lp_strnstr \
		lp_strrchr \
		lp_strtrim \
		lp_str_isequal \
		lp_atof \
		lp_strcat \
		lp_strfusion \
		lp_atoi_base \
		lp_itoa_base \
		lp_uitoa_base \
		lp_ultoa_base

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