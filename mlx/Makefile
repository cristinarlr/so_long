# Colors ----------------------------------------------------- #
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
CIAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m

# ------------------------------------------------------------ #
NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11
CFLAGS+= -Wno-deprecated-declarations

#crramire i´ve added > /dev/null 2>&1 to silence ar and ranlib exit 
all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ) > /dev/null 2>&1
	@ranlib $(NOM) > /dev/null 2>&1
	@echo "$(GREEN)[+] $(BLUE) $(NOM) compilada! $(END)"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(MAGENTA)[+] $(BLUE)  Archivos *~ y mlx_app de $(NOM) borrados $(END)"

fclean: clean
	@$(RM) $(NOM)
	@echo "$(MAGENTA)[+] $(BLUE) $(NOM) borrado $(END)"

re: clean all
