NAME     := libftprintf.a
SRCS     := \


OBJS     := $(SRCS:.c=.o)
CC       := cc
CFLAGS   := -Wall -Wextra -Werror
CPPFLAGS := -I include
AR       := ar
ARFLAGS  := -rcs
RM       := rm -ff

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re