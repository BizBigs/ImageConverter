NAME	=	img-converter

SRC		=	src/main.c \
			src/JpegManager.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

INC_DIR =	./includes

LIBS			+=		-L/usr/lib/x86_64-linux-gnu -ljpeg

CFLAGS			+=      -ansi -pedantic -Wextra -Werror -Wall -I$(INC_DIR) 

SUCCESS			=       \033[32;1m[Compilation succeeded]\033[0m

OBJRM           =       \033[32;1m[Sources Objects Removed]\033[0m

NAMERM          =       \033[32;1m[Sources Names Removed]\033[0m

FAIL            =       \033[31;1m[Compilation failed]\033[0m

all:            $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIBS) && echo "$(SUCCESS)" || echo "$(FAIL)"

clean:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*\#
	@echo "$(OBJRM)"

fclean:         clean
	@$(RM) $(NAME)
	@echo "$(NAMERM)"

re:         fclean all
