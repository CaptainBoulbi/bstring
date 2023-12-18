PROJECTNAME=bstring
BIN=build/$(PROJECTNAME)
CC=gcc

# make mode=release
ifeq ($(mode), release)
	OPT=-O3
else
	OPT=-Og -g
endif
DEPFLAGS=-MP -MD
FLAGS=-Wall -Wextra -I. $(OPT) $(DEPFLAGS) $(foreach M,$(MACROS),-D$(M))

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=build/%.o)
TEST=$(wildcard test/*.c)
TESTO=$(TEST:test/%.c=build/%.t)

$(shell mkdir -p build)


all : $(BIN)

$(BIN) : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

-include $(OBJ:.o=.d) $(LIBO:.o=.d)

build/%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

# make test file=testGenID.cpp
test : build/$(file).t
	./build/$(file).t

alltest : $(TESTO)
	@for i in $(TESTO); do echo $$i; $$i; done

build/%.t : test/%.c build/$(PROJECTNAME).o
	$(CC) $(FLAGS) $^ -o $@

# make run input="program input"
run : $(BIN)
	./$< $(input)

clean :
	rm -rf build/*

check :
	cppcheck --enable=all --suppress=missingIncludeSystem -I.
	flawfinder .
	clang-tidy $(SRC) *.h
	gcc -fanalyzer $(SRC) $(FLAGS)
	rm a-*.d a.out

debug : $(BIN)
	gdb $< $(input)

# unzip : tar -xvf exemple.tgz
dist : clean
	$(info /!\ project folder has to be named $(PROJECTNAME) /!\ )
	cd .. && tar zcvf $(PROJECTNAME)/build/$(PROJECTNAME).tgz $(PROJECTNAME) >/dev/null

push :
	git push bbsrv
	git push gh

install : dist
	cp Makefile ../script
	mv build/$(PROJECTNAME).tgz ../opt/archive

# alias

r : run

t : test

c : check

p : push

d : debug

.PHONY : all test t alltest run r clean check c debug d dist push p install
