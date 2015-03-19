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
TESTDIR= tests
SRCDIR = src

# Flags
CFLAGS = -Wall -pedantic -std=c++11

# Source Files 
OBJS = $(addprefix $(OBJDIR)/, \
	AsciiView.o \
	Board.o \
	Dice.o \
	Game.o \
	utils.o \
	Controller.o \
	InteractiveCli.o \
	UserInputValidation.o \
	Phase.o \
	Player.o\
)

# Test Files
TESTNAMES = \
	AsciiView_tests \
	Board_tests \
	Controller_tests \
	Dice_tests \
	Game_tests \
	Validation_tests \
	InteractiveCli_tests \
	UserInputValidation_tests \
	Phase_tests \
	testmain



TESTS =    $(addprefix $(TESTDIR)/,$(addsuffix .cc,$(TESTNAMES)))
TESTOBJS = $(addprefix $(TESTDIR)/,$(addsuffix .o,$(TESTNAMES)))

.PHONY: all
all: main test

.PHONY: main
main: $(OBJS)
	g++ $(CFLAGS) $(OBJS) $(SRCDIR)/main.cc -lreadline -o $@

# Test
############################################################
.PHONY: test
test: main_unittest

INCLUDES  = -isystem ${GTEST_DIR}/include 
LIBRARIES = -lreadline -pthread

main_unittest: libgtest.a $(OBJS) $(TESTOBJS)
	g++ -std=c++11 $(INCLUDES) $(TESTOBJS) $(OBJS) libgtest.a \
	-o $@ $(LIBRARIES)

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
$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	#Making $@
	@g++ $(CFLAGS) -c -o $@ $<

$(TESTDIR)/%.o: $(TESTDIR)/%.cc
	#Making $@
	@g++ $(CFLAGS) -c -o $@ $< $(INCLUDES)






# Clean
##########################################################
clean:	
	rm -rf $(OBJDIR)/*
	rm -f libgtest.a
	rm -f gtest-all.o
	rm -f main
	rm -f main_unittest
	rm -f $(TESTDIR)/*.o


# Dependencies (Unused right now, may want in the future)
##########################################################
### Running "make depend" automatically generates dependencies for our object files
### it searches for the header files that a file depends on and lists them as dependencies
### it then appends those dependencies to the bottom of the file, right here!
### depend:
### 	gccmakedep -- $(CFLAGS) -- src/*
