NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Directories
SRC_DIR		= src/
INC_DIR		= inc/
OBJ_DIR		= obj/

# Source files
SRCS		= $(SRC_DIR)main.c \
			  $(SRC_DIR)f_init_sim.c \
			  $(SRC_DIR)f_init_forks.c \
			  $(SRC_DIR)f_init_philos.c \
			  $(SRC_DIR)f_destroy_forks.c \
			  $(SRC_DIR)f_create_threads.c \
			  $(SRC_DIR)f_utils.c \
			  $(SRC_DIR)f_monitor_philos.c\
			  $(SRC_DIR)f_philo_routine.c

# Object files
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Include flags
INC			= -I$(INC_DIR)

all:		$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

# Compilation rule
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
