CC = g++

SDIR = ./src
IDIR = ./include
BDIR = ./build
ODIR = $(BDIR)/obj

EXEC = $(BDIR)/sea

# input flex/yacc files
FLEXI = sea.l
YACCI = sea.y

# output flex/yacc files
FLEXO = yyscanner
YACCO = yyparser

CFLAGS = -g -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-function -I$(IDIR) -I/usr/include/

_DEPS = $(YACCO).hpp stack.hh sea_debug.h sea_str.h sea_scope.h sea_translator.h sea.h lexer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = $(YACCO).o $(FLEXO).o sea_str.o sea_scope.o sea_translator.o sea.o lexer.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: build
.PHONY: compile
.PHONY: run
.PHONY: exec
.PHONY: clean

# create build directory
# generate scanner with lex
# generate parser with yacc
# compile generated files
build:
	@mkdir -p $(ODIR)
	@lex -o $(SDIR)/$(FLEXO).c $(FLEXI)
	@yacc --language=c++ --defines=$(IDIR)/$(YACCO).hpp -o $(SDIR)/$(YACCO).cpp $(YACCI)
	@mv src/stack.hh include/stack.hh
	@make compile

compile: $(OBJS)
	$(CC) -o $(EXEC) $^ $(CFLAGS)

run:
	@make build
	@make exec

exec:
	$(EXEC)

clean:
	@rm -r $(BDIR)
	@rm $(SDIR)/$(FLEXO).c
	@rm $(SDIR)/$(YACCO).c
	@rm $(IDIR)/$(YACCO).h
