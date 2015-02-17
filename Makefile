# list of gcc options (useful for finding what -I or -isystem mean)
# 	Index:   https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Option-Index.html#Option-Index

# Comments outside of a 'target' aren't displayed
# put @ symbol before a comment in a target to not display it when running


all:
	@# compile the gtest-all.cc source file to gtest-all.o object file
	@# the -c flag means it compiles and assembles, without linking
	@# this is generally how you end up with object files I think

	@# the -isystem and -I /BASICALLY/ just include those directories to the list of directories to be searched for header files
	@# the pthread library is used
	@# gtest-all.cc is the src file being compiled
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
		-pthread -c ${GTEST_DIR}/src/gtest-all.cc

	@# create the libgtest.a file from the gtest-all.o file
	@# a '.a' file is a static library made up of some objects?
	ar -rv libgtest.a gtest-all.o 


	@# compile tests/inittest.cc and /LINK/ to libgtest.a
	@# remember the -c flag is used in the first command to do compilation without linking
	@# include pthread library as well as the GTEST/include directory
	@# set the compiler to think about c++ as the c++11 standard so we can do certain cooler things
	@# output the result to 'your_test'
	g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread tests/inittest.cc libgtest.a \
		-o main_unittest

clean:
	@# remove the archive file and object files from the first two steps of making
	rm -f *.o
	rm -f *.a

test:

	make clean

	clear 

	make

	./main_unittest