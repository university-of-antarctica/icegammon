# list of gcc options (useful for finding what -I or -isystem mean)
# 	Index:   https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Option-Index.html#Option-Index

# Notes on make:
	# Comments outside of a 'target' aren't displayed
	# put @ symbol before a comment in a target to not display it when running

	# Define variables outside of targets and then reference them by $(NAME)


############################################################
# The Compiler
CC = g++
# Flags
FLAGS = -std=c++11
# Tests
TESTS = tests/inittest.cc
# Includes
INCLUDES = -isystem ${GTEST_DIR}/include -pthread
# Out
OUT = main_unittest

# compile tests/inittest.cc and /LINK/ to libgtest.a
# remember the -c flag is used in the first command to do compilation without linking
# include pthread library as well as the GTEST/include directory
# set the compiler to think about c++ as the c++11 standard so we can do certain cooler things
# output the result to 'your_test'
all: libgtest.a
	$(CC) $(FLAGS) $(INCLUDES) $(TESTS) libgtest.a \
		-o $(OUT)


########################################################
# create the libgtest.a file from the gtest-all.o file
# a '.a' file is a static library made up of some objects?

libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o 


########################################################
gtest-all_CC = g++
gtest-all_INCLUDES = $(INCLUDES) -I${GTEST_DIR}
# the -c flag means it compiles and assembles, without linking
gtest-all_FLAGS = -c
gtest-all_TARGET = ${GTEST_DIR}/src/gtest-all.cc
gtest-all.o: 
	$(gtest-all_CC) $(gtest-all_INCLUDES) $(gtest-all_FLAGS) $(gtest-all_TARGET)
#######################################################

# remove the archive file and object files from the first two steps of making
clean:	
	rm -f *.o
	rm -f *.a
	rm -f *_unittest

########################################################

# clears working directory and gives us a fresh terminal to look at test output
# prepended hyphen means that make will not complain if we fail the tests
test: 
	clear
	make clean
	make all
	make run

########################################################
# prepended hyphen means that make will not complain if we fail the tests
RUNTEST = -./$(OUT)
run:
	$(RUNTEST)

#.IGNORE: run
