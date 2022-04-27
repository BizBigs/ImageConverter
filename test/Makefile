NAME					=	img-converter

SRC						=	src/main.c

OBJ						=	$(SRC:.c=.o)

INC_DIR 				=	../includes

CC						=	gcc

RM						=	rm -f

DYNAMIC_LIB_DIR 		= 	../lib

LIBS					+=	libimg-converter.so

CFLAGS					+=	-ansi -pedantic -Wextra -Werror -Wall -I$(INC_DIR)

SUCCESS					=	\033[32;1m[Compilation succeeded]\033[0m

OBJRM           		=	\033[32;1m[Sources Objects Removed]\033[0m

NAMERM          		=	\033[32;1m[Sources Names Removed]\033[0m

FAIL            		=	\033[31;1m[Compilation failed]\033[0m

LIBCREATED      		=	\033[32;1m[Library Succesfully Created]\033[0m

all:            $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ)
	@$(CC) $(OBJ) $(OBJEXE) -o $(NAME) $(DYNAMIC_LIB_DIR)/$(LIBS) && echo "$(SUCCESS)" || echo "$(FAIL)"

clean:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*\#
	@echo "$(OBJRM)"

fclean:         clean
	@$(RM) $(NAME)
	@echo "$(NAMERM)"

re:         fclean all