# variable

CC = gcc

EXEC = rsa
ARCHIVE = BOUTON_Nicolas
TAR = tar.gz

SRCDIR = src
OBJDIR = obj

DEPS = $(wildcard $(SRCDIR)/*.h)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

FLAG = -Wall -g3

# make

all: config compil

compil: $(OBJ)
	@ $(CC) -o $(EXEC) $(OBJ)
	@ echo "Linking complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@ $(CC) -c -o $@ $< $(FLAG)
	@ echo "Compiled "$@" successfully!"

run:
	@ ./$(EXEC)

clean:
	@ if [ $(ARCHIVE).$(TAR) ]; then rm -f $(ARCHIVE).$(TAR); echo "Archive removed!"; fi
	@ rm -rf $(OBJDIR)
	@ echo "Object files removed!"
	@ rm -f $(EXEC)
	@ echo "Executable removed!"
	
package: clean
	@ tar -czvf $(ARCHIVE).$(TAR) *
	@ echo "Archive created!"


config:
	@ $(shell ./script)

install:
	@ sudo apt-get install libgmp3-dev