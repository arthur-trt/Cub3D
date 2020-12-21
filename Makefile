#Compiler and Linker
CC				:= clang-9

#The Target Binary Program
TARGET			:= cub3D

#Release of debug compile
BUILD			:= release

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR			:= src
INCDIR			:= inc
BUILDDIR		:= obj
TARGETDIR		:= bin
SRCEXT			:= c
DEPEXT			:= d
OBJEXT			:= o

SOURCES			:= src/main.c src/tools/error.c src/tools/sprite.c src/tools/files.c src/tools/utils.c src/tools/map.c src/tools/draw.c src/tools/textures.c src/tools/str.c src/tools/init2.c src/tools/mlx.c src/tools/init.c src/tools/cub.c src/tools/free.c src/parser/cub_parser.c src/parser/args_parser.c src/parser/map_parser.c src/engine/player.c src/engine/sprite.c src/engine/raycasting.c src/engine/camera.c src/engine/cub3d.c src/engine/dda.c src/rendering/render_f_c.c src/rendering/bitmap.c src/rendering/render_sprite.c src/rendering/render_texture.c src/debug/print_info.c src/managers/keys.c src/managers/windows.c
OBJECTS			:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Flags, Libraries and Includes
cflags.release	:= -Wall -Werror -Wextra -ggdb
cflags.debug	:= -Wall -Werror -Wextra -DDEBUG -ggdb -fsanitize=address -fno-omit-frame-pointer
CFLAGS 			:= $(cflags.$(BUILD))
LIB				:= -lm -lmlx -Llibftprintf -lftprintf -lXext -lX11
INC				:= -I$(INCDIR) -I/usr/local/include
INCDEP			:= -I$(INCDIR)

# Colors
C_RESET			:= \033[0m
C_PENDING		:= \033[0;36m
C_SUCCESS		:= \033[0;32m

# Multi platforms
ECHO			:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE		:= "\033[1A\033[2K\033[1A"
ERASE			:= $(ECHO) $(ES_ERASE)

# hide STD/ERR and prevent Make from returning non-zero code
HIDE_STD		:= > /dev/null
HIDE_ERR		:= 2> /dev/null || true

GREP			:= grep --color=auto --exclude-dir={.bzr,CVS,.git,.hg,.svn}
NORMINETTE		:= norminette `ls | grep -v "_main*" | grep -v "test*"`

#Defauilt Make
all: directories $(TARGET)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

#Remake
re: fclean all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	@make $@ -s -C libftprintf/
	@$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
fclean: clean
	@make $@ -s -C libftprintf/
	@$(RM) -rf $(TARGETDIR)

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@make -s -C libftprintf/
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@$(ERASE)
	@$(ERASE)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

libft:
	@make -s -C libftprintf/

norm:
	@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

#Non-File Targets
.PHONY: all re clean fclean norm
