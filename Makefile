CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm -g

SRCDIR = src
INCLUDEDIR = include
BUILDDIR = build

SRCFILES = $(wildcard $(SRCDIR)/*.c)
BUILDFILES = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: buildfolder cll-tools

cll-tools: $(BUILDFILES) 
	@ echo "Compiling objects to executable."
	$(CC) $(CFLAGS) $(BUILDFILES) -o $@ $(LDFLAGS)

buildfolder:
	@ echo "Creating object folder."
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/main.o: $(SRCDIR)/main.c
	@ echo "Creating main object."
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(INCLUDEDIR)/%.h
	@ echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	rm main
	rm -r $(BUILDDIR)

