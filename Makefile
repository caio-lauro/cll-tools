CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lm -g

SRCDIR = src
INCLUDEDIR = include
BUILDDIR = build

SRCFILES = $(wildcard $(SRCDIR)/*.c)
BUILDFILES = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: buildfolder cll-tools

buildfolder:
	@ echo "Creating object folder."
	mkdir -p $(BUILDDIR)

cll-tools: buildfolder $(BUILDFILES) 
	@ echo "Compiling objects to executable."
	$(CC) $(CFLAGS) $(BUILDFILES) -o $@ $(LDFLAGS)

$(BUILDDIR)/main.o: $(SRCDIR)/main.c
	@ echo "Creating main object."
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(INCLUDEDIR)/%.h
	@ echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY: clean install uninstall

clean:
	rm cll-tools
	rm -r $(BUILDDIR)

# Borrowed from stackoverflow 76088273
prefix ?= /usr/local
binpath = $(prefix)/bin
install: cll-tools
	install -m 755 cll-tools $(binpath)

uninstall:
	rm -f $(binpath)/cll-tools
