
#defining the name of the static library
NAME = libftprintf.a

#compiler and flags -I finds header files in libft_files so libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft_files

#all of the source files
SRC = ft_printf.c ft_print_numbers.c ft_print_text.c ft_hex.c

#convert c files to object files (.c to .o) - doesnt build yet
OBJ = $(SRC:.c=.o)

#Default command - buld the library libftprintf.a by running make
all: $(NAME)

# Checks all the .o files in $(OBJ) exist to build $(NAME)/create library.
$(NAME): $(OBJ)
	make -C libft_files
	cp libft_files/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) libft_files/libft.a
#this line above actually runs to build library.
#ar (archiver) used to create static libraries (.a)
#r replaces file in archive/adds if not there. c creates archive if it doesnt exist yet.
#s tells ar to write an index (symbol table)- linker can quickly locate symbols.


# Compile .c files to .o files - teaches how to build a .o file from a .c file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#so if any are missing it does gcc -Wall -Werror -Wextra filename.c -o filename.o

# Clean object files
clean:
	rm -f $(OBJ)
	make -C libft_files clean

# Clean everything including the library
fclean: clean
	rm -f $(NAME)
	make -C libft_files fclean

#rebuilds it all.
re: fclean all

#UNIT TEST 
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
#	gcc -nostartfiles -shared -o libft.so $(OBJ)

#test: $(NAME) main.o
#	$(CC) $(CFLAGS) main.o -L. -lftprintf -o test

#main.o: main.c
#	$(CC) $(CFLAGS) -c main.c -o main.o

.PHONY: all clean fclean re
