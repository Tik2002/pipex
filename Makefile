NAME = pipex
SRCSPATH = ./srcs/
PRINTF_PATH = ./printf/
LIBFTPATH = ./libft/
INCPATH = ./includes/ ./printf/includes/ ./printf/libft/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))
PRINTF = $(PRINTF_PATH)/srcs/*.o
LIBFT = $(LIBFTPATH)*.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -c $(foreach H,$(INCPATH),-I$(H))
#
all : $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)
#
$(LIBFT) :
	make -C $(LIBFTPATH) all

$(PRINTF) :
	make -C $(PRINTF_PATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) $< -o $@
#
clean :
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTF_PATH) fclean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
