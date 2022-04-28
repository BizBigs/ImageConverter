.PHONY : clean

OUT_FILE_NAME 			= 	libimg-converter.so

SRC						=	src/JpegManager.c \
							src/PngManager.c \
							src/ImageManager.c

OBJ						=	$(SRC:.c=.o)

IMGCONVERTER_LIBDIR		=	./lib
TARGET					=	$(IMGCONVERTER_LIBDIR)/$(OUT_FILE_NAME)

CC						=	gcc

RM						=	rm -f

INC_DIR 				=	./includes

LDFLAGS 				=	-shared

LIBS					+=	-L/usr/lib/x86_64-linux-gnu -ljpeg -lpng

CFLAGS					+=	-ansi -pedantic -Wextra -Werror -Wall -I$(INC_DIR) -fPIC

SUCCESS					=	\033[32;1m[Compilation succeeded]\033[0m

OBJRM           		=	\033[32;1m[Sources Objects Removed]\033[0m

NAMERM          		=	\033[32;1m[Sources Names Removed]\033[0m

FAIL            		=	\033[31;1m[Compilation failed]\033[0m

LIBCREATED      		=	\033[32;1m[Library Succesfully Created]\033[0m

all:	$(TARGET)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(TARGET)
	@$(RM) *~
	@$(RM) \#*\#
	@echo "$(OBJRM)"

re:         clean all

$(TARGET) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)
	@echo "$(LIBCREATED)"