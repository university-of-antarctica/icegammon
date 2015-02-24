# list of gcc options (useful for finding what -I or -isystem mean)
# 	Index:   https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Option-Index.html#Option-Index

# Notes on make:
	# Comments outside of a 'target' aren't displayed
	# put @ symbol before a comment in a target to not display it when running

	# Define variables outside of targets and then reference them by $(NAME)
	# phony
	# define targets, recipes, dependencies
	# * expansion doesn't happen here like in dependencies, but will in a g++ command


# Directories
OBJDIR = build
SRCDIR = src

# Flags
CFLAGS = -Wall -pedantic -std=c++11

# Files 
OBJS = $(addprefix $(OBJDIR)/,AsciiView.o Board.o Dice.o Game.o utils.o Controller.o)

.PHONY: all
all: main test

.PHONY: main
main: $(OBJS)
	g++ $(CFLAGS) $(OBJS) $(SRCDIR)/main.cc -o $@

# Test
############################################################
.PHONY: test
test: main_unittest

INCLUDES = -isystem ${GTEST_DIR}/include -lreadline -pthread
main_unittest: libgtest.a $(OBJS)
	g++ -std=c++11 $(INCLUDES) tests/* $(OBJS) libgtest.a \
	-o $@

# Google Test static library file
libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o 

# Google Test object file
gtest-all.o: 
	g++ -isystem ${GTEST_DIR}/include -pthread -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc



# (Automatic) Source Files
############################################################
# rule to make targets that look like build/*.o
# relying upon files like src/*.cc
# $@ refers to the target name (build/*.o) as the output file
# $< refers to the first prerequisite (src/*.o) as the g++ target
$(OBJDIR)/%.o : $(SRCDIR)/%.cc
	g++ $(CFLAGS) -c -o $@ $<




# Clean
##########################################################
clean:	
	rm -rf $(OBJDIR)/*
	rm -f libgtest.a
	rm -f gtest-all.o
	rm -f main
	rm -f main_unittest


# Dependencies (Unused right now, may want in the future)
##########################################################
### Running "make depend" automatically generates dependencies for our object files
### it searches for the header files that a file depends on and lists them as dependencies
### it then appends those dependencies to the bottom of the file, right here!
### depend:
### 	gccmakedep -- $(CFLAGS) -- src/*
