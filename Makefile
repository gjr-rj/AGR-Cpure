CC         = clang
EXECNAME   = regeal.exe
PROJECTDIR = ./
BINARYDIR  = $(PROJECTDIR)bin
SRCDIR     = src

INCLUDERELDIR  = include
LIBSANITIZEDIR = sanitize
LIBTDDDIR      = tdd

INCLUDES = \
           -I$(INCLUDERELDIR) \
           -I$(LIBSANITIZEDIR) \
		   -I$(LIBSANITIZEDIR)/$(INCLUDERELDIR) \
           -I$(LIBTDDDIR) \
		   -I$(LIBTDDDIR)/$(INCLUDERELDIR)

FLAGS = -Wall

ifeq ($(debug), 1)
FLAGS := $(FLAGS) -g
endif

ifeq ($(sanitize), 1)
FLAGS := $(FLAGS) -D_RUN_SANITIZE
endif

ifeq ($(smoke), 1)
FLAGS := $(FLAGS) -D_RUN_SMOKE
endif

SOURCE = main.c \
         $(LIBSANITIZEDIR)/sanitize.c \
		 $(LIBTDDDIR)/tdd.c \
		 $(LIBTDDDIR)/tddsanitize.c

all: format
	$(CC) -working-directory=$(PROJECTDIR) $(SOURCE) $(INCLUDES) -o  \
	$(BINARYDIR)/$(EXECNAME) $(FLAGS)

format:
	find ./ -iname *.h -o -iname *.c | xargs clang-format -i

clean:
	$(RM) $(BINARYDIR)/$(EXECNAME)
