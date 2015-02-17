all:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
		-pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o 

	g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread tests/inittest.cc libgtest.a \
		-o your_test 

clean:
	rm *.o