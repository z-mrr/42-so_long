NAME    = so_long

NAME_B  = so_long_bonus

INC     = /usr/local/include# could be /usr/include depending on your OS

INCFT   = ./libft# header from libft

LIBFT   = ./libft# path to libft library

LIBMLX  = /usr/local/lib# could be /usr/lib, depends on where you decided to put your mlx library

UNAME   := $(shell uname)# get the OS name, this will help define behaviors for certain OS's

CFLAGS  = -Wall -Werror -Wextra -O3 -g -I$(INC) -I${INCFT}# -fsanitize=address # C Flags (gcc) & linking. "-Iinclude" if you created the folder "include" to put your project headers"

LFLAGS  = -lmlx -L${LIBFT} -lft# -fsanitize=address# if you decided to install libmlx.a locally you don't need "-L$(LIBMLX) -lmlx" the school also has it locally as well...

SRC     = $(wildcard src/*.c)# list your source files

SRC_B     = $(wildcard src_bonus/*.c)# list your source files

OBJ     = $(SRC:%.c=%.o)# convert source files to binary list

OBJ_B     = $(SRC_B:%.c=%.o)# convert source files to binary list

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC = clang
else #Linux and others...
	CC = gcc
	LFLAGS += -lbsd -lXext -lX11 -lm -L. -lXext
endif

all: $(NAME)

bonus: $(NAME_B)

$(NAME): runlibft $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "Finished compiling... --> ${NAME}"

$(NAME_B): runlibft $(OBJ_B)
	@$(CC) -o $(NAME_B) $(OBJ_B) $(LFLAGS)
	@echo "Finished compiling... --> ${NAME_B}"

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME		: $(NAME)\n"
	@printf "NAME_B		: $(NAME_B)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
	@printf "SRC_B		: $(SRC_B)\n"
	@printf "OBJ_B		: $(OBJ_B)\n"

runlibft:
	@make -C libft --no-print-directory

norm:
	norminette -R CheckForbiddenSourceHeader ${SRC}
	norminette -R CheckDefine src/so_long.h

clean:
	rm -f $(OBJ) $(OBJ_B)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME) $(NAME_B)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY : all clean fclean re bonus
