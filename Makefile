CC = gcc

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

CFLAGS = -Wall -Werror -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-function -I$(IDIR)

_DEPS = $(YACCO).h sea_node.h sea_translator.h sea_internal.h sea_stack.h sea_debug.h sea.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = $(YACCO).o $(FLEXO).o sea_node.o sea_translator.o sea_stack.o sea.o
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
	@yacc --defines=$(IDIR)/$(YACCO).h -o $(SDIR)/$(YACCO).c $(YACCI)
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
