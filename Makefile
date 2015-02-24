# list of gcc options (useful for finding what -I or -isystem mean)
# 	Index:   https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Option-Index.html#Option-Index

# Notes on make:
	# Comments outside of a 'target' aren't displayed
	# put @ symbol before a comment in a target to not display it when running

	# Define variables outside of targets and then reference them by $(NAME)
	# phony
	# define targets, recipes, dependencies
	# * expansion doesn't happen here like in dependencies, but will in a g++ command


# Source files
S_NAMES = AsciiView Board Dice Game utils
S_PATHS = $(addsuffix .cc, $(addprefix src/,$(S_NAMES)))
S_OBJS = $(addsuffix .o, $(S_NAMES))


# Main
############################################################
main: main.o objs
	echo $(S_OBJS)
	g++ $(S_OBJS) main.o -o $@

# Test
############################################################
test: main_unittest

T_NAMES = AsciiView_tests Board_tests Dice_tests Game_tests testmain
T_PATHS = $(addsuffix .cc, $(addprefix tests/,$(T_NAMES)))
T_OBJS = $(addsuffix .o, $(addprefix tests/,$(T_NAMES)))
CFLAGS = -std=c++11 -c

testobjs: $(T_OBJS)

AsciiView_tests.o:
	g++ $(CFLAGS) $< -o $@
Board_tests.o:
	g++ $(CFLAGS) $< -o $@
Dice_tests.o:
	g++ $(CFLAGS) $< -o $@
Game_tests.o:
	g++ $(CFLAGS) $< -o $@
testmain.o:
	g++ $(CFLAGS) $< -o $@

# Objects
###################################################
# $@ refers to the name of the target
# $< refers to the first dependency of the target
# 	No dependencies are mentioned here, but the dependencies are generated below
#	It seems like the makefile yanks up the dependencies at the bottom of the file
#	and puts them after the colon for these targets.  No problem with multiple
#	definitions of the targets! At least when there's only one recipe (right here)

# Take the SOURCES macro and replace all of the .cc with .o in the file names
CFLAGS = -std=c++11 -c
objs: $(S_OBJS)

AsciiView.o:
	g++ $(CFLAGS) $< -o $@
Board.o: 
	g++ $(CFLAGS) $< -o $@
Dice.o: 
	g++ $(CFLAGS) $< -o $@
Game.o: 
	g++ $(CFLAGS) $< -o $@
utils.o: 
	g++ $(CFLAGS) $< -o $@

##########
main.o: 
	g++ $(CFLAGS) $< -o $@


# Unit Tests
###########################################################
INCLUDES = -isystem ${GTEST_DIR}/include -pthread
main_unittest: libgtest.a objs
	g++ -std=c++11 $(INCLUDES) tests/* $(S_OBJS) libgtest.a \
	-o $@

# Google Test static library file
libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o 

# Google Test object file
gtest-all.o: 
	g++ -isystem ${GTEST_DIR}/include -pthread -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc



# Phonies
##########################################################
# This PHONY target lets 'make' know that the targets mentioned here as 'dependencies'
# aren't actually targets that get created 
.PHONY: test clean depend objs

# Clean
##########################################################
clean:	
	rm -f *.o
	rm -f *.a
	rm -f *_unittest
	rm -f *.out
	rm -f main


# Dependencies
########################################################
# "make depend" automatically generates dependencies for our object files
# it searches for the header files that a file depends on and lists them as dependencies
# it then appends those dependencies to the bottom of the file, right here!
depend:
	gccmakedep -Y -- $(CFLAGS) -- $(S_PATHS) $(T_PATHS) src/main.cc



# DO NOT DELETE
AsciiView.o: src/AsciiView.cc /usr/include/stdc-predef.h src/AsciiView.h \
 /usr/include/c++/4.9/string \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/cpu_defines.h \
 /usr/include/c++/4.9/bits/stringfwd.h \
 /usr/include/c++/4.9/bits/memoryfwd.h \
 /usr/include/c++/4.9/bits/char_traits.h \
 /usr/include/c++/4.9/bits/stl_algobase.h \
 /usr/include/c++/4.9/bits/functexcept.h \
 /usr/include/c++/4.9/bits/exception_defines.h \
 /usr/include/c++/4.9/bits/cpp_type_traits.h \
 /usr/include/c++/4.9/ext/type_traits.h \
 /usr/include/c++/4.9/ext/numeric_traits.h \
 /usr/include/c++/4.9/bits/stl_pair.h /usr/include/c++/4.9/bits/move.h \
 /usr/include/c++/4.9/bits/concept_check.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.9/debug/debug.h \
 /usr/include/c++/4.9/bits/stl_iterator.h \
 /usr/include/c++/4.9/bits/ptr_traits.h \
 /usr/include/c++/4.9/bits/predefined_ops.h \
 /usr/include/c++/4.9/bits/postypes.h /usr/include/c++/4.9/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/xlocale.h /usr/include/c++/4.9/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++allocator.h \
 /usr/include/c++/4.9/ext/new_allocator.h /usr/include/c++/4.9/new \
 /usr/include/c++/4.9/exception \
 /usr/include/c++/4.9/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.9/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++locale.h \
 /usr/include/c++/4.9/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/4.9/iosfwd \
 /usr/include/c++/4.9/cctype /usr/include/ctype.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/4.9/bits/ostream_insert.h \
 /usr/include/c++/4.9/bits/cxxabi_forced.h \
 /usr/include/c++/4.9/bits/stl_function.h \
 /usr/include/c++/4.9/backward/binders.h \
 /usr/include/c++/4.9/bits/range_access.h \
 /usr/include/c++/4.9/bits/basic_string.h \
 /usr/include/c++/4.9/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/atomic_word.h \
 /usr/include/c++/4.9/bits/basic_string.tcc src/Board.h
Board.o: src/Board.cc /usr/include/stdc-predef.h src/Board.h
Dice.o: src/Dice.cc /usr/include/stdc-predef.h src/Dice.h \
 /usr/include/time.h /usr/include/features.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h /usr/include/xlocale.h \
 /usr/include/stdlib.h /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stdint.h /usr/include/stdint.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h /usr/include/c++/4.9/utility \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/os_defines.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/cpu_defines.h \
 /usr/include/c++/4.9/bits/stl_relops.h \
 /usr/include/c++/4.9/bits/stl_pair.h /usr/include/c++/4.9/bits/move.h \
 /usr/include/c++/4.9/bits/concept_check.h
Game.o: src/Game.cc /usr/include/stdc-predef.h src/Game.h src/Color.h
utils.o: src/utils.cc /usr/include/stdc-predef.h src/utils.h \
 /usr/include/c++/4.9/numeric \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/cpu_defines.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.9/bits/stl_numeric.h \
 /usr/include/c++/4.9/bits/concept_check.h \
 /usr/include/c++/4.9/debug/debug.h /usr/include/c++/4.9/bits/move.h \
 /usr/include/c++/4.9/algorithm /usr/include/c++/4.9/utility \
 /usr/include/c++/4.9/bits/stl_relops.h \
 /usr/include/c++/4.9/bits/stl_pair.h \
 /usr/include/c++/4.9/bits/stl_algobase.h \
 /usr/include/c++/4.9/bits/functexcept.h \
 /usr/include/c++/4.9/bits/exception_defines.h \
 /usr/include/c++/4.9/bits/cpp_type_traits.h \
 /usr/include/c++/4.9/ext/type_traits.h \
 /usr/include/c++/4.9/ext/numeric_traits.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.9/bits/stl_iterator.h \
 /usr/include/c++/4.9/bits/ptr_traits.h \
 /usr/include/c++/4.9/bits/predefined_ops.h \
 /usr/include/c++/4.9/bits/stl_algo.h /usr/include/c++/4.9/cstdlib \
 /usr/include/stdlib.h /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h /usr/include/xlocale.h \
 /usr/include/x86_64-linux-gnu/sys/types.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h \
 /usr/include/c++/4.9/bits/algorithmfwd.h \
 /usr/include/c++/4.9/bits/stl_heap.h \
 /usr/include/c++/4.9/bits/stl_tempbuf.h \
 /usr/include/c++/4.9/bits/stl_construct.h /usr/include/c++/4.9/new \
 /usr/include/c++/4.9/exception \
 /usr/include/c++/4.9/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.9/ext/alloc_traits.h \
 /usr/include/c++/4.9/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++allocator.h \
 /usr/include/c++/4.9/ext/new_allocator.h \
 /usr/include/c++/4.9/bits/memoryfwd.h /usr/include/c++/4.9/cmath \
 /usr/include/math.h /usr/include/x86_64-linux-gnu/bits/huge_val.h \
 /usr/include/x86_64-linux-gnu/bits/huge_valf.h \
 /usr/include/x86_64-linux-gnu/bits/huge_vall.h \
 /usr/include/x86_64-linux-gnu/bits/inf.h \
 /usr/include/x86_64-linux-gnu/bits/nan.h \
 /usr/include/x86_64-linux-gnu/bits/mathdef.h \
 /usr/include/x86_64-linux-gnu/bits/mathcalls.h \
 /usr/include/c++/4.9/vector \
 /usr/include/c++/4.9/bits/stl_uninitialized.h \
 /usr/include/c++/4.9/bits/stl_vector.h \
 /usr/include/c++/4.9/bits/stl_bvector.h \
 /usr/include/c++/4.9/bits/range_access.h \
 /usr/include/c++/4.9/bits/vector.tcc
main.o: src/main.cc /usr/include/stdc-predef.h src/Board.h \
 src/AsciiView.h /usr/include/c++/4.9/string \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/cpu_defines.h \
 /usr/include/c++/4.9/bits/stringfwd.h \
 /usr/include/c++/4.9/bits/memoryfwd.h \
 /usr/include/c++/4.9/bits/char_traits.h \
 /usr/include/c++/4.9/bits/stl_algobase.h \
 /usr/include/c++/4.9/bits/functexcept.h \
 /usr/include/c++/4.9/bits/exception_defines.h \
 /usr/include/c++/4.9/bits/cpp_type_traits.h \
 /usr/include/c++/4.9/ext/type_traits.h \
 /usr/include/c++/4.9/ext/numeric_traits.h \
 /usr/include/c++/4.9/bits/stl_pair.h /usr/include/c++/4.9/bits/move.h \
 /usr/include/c++/4.9/bits/concept_check.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.9/debug/debug.h \
 /usr/include/c++/4.9/bits/stl_iterator.h \
 /usr/include/c++/4.9/bits/ptr_traits.h \
 /usr/include/c++/4.9/bits/predefined_ops.h \
 /usr/include/c++/4.9/bits/postypes.h /usr/include/c++/4.9/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/xlocale.h /usr/include/c++/4.9/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++allocator.h \
 /usr/include/c++/4.9/ext/new_allocator.h /usr/include/c++/4.9/new \
 /usr/include/c++/4.9/exception \
 /usr/include/c++/4.9/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.9/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++locale.h \
 /usr/include/c++/4.9/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/4.9/iosfwd \
 /usr/include/c++/4.9/cctype /usr/include/ctype.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/4.9/bits/ostream_insert.h \
 /usr/include/c++/4.9/bits/cxxabi_forced.h \
 /usr/include/c++/4.9/bits/stl_function.h \
 /usr/include/c++/4.9/backward/binders.h \
 /usr/include/c++/4.9/bits/range_access.h \
 /usr/include/c++/4.9/bits/basic_string.h \
 /usr/include/c++/4.9/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/atomic_word.h \
 /usr/include/c++/4.9/bits/basic_string.tcc src/Dice.h \
 /usr/include/stdlib.h /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stdint.h /usr/include/stdint.h \
 /usr/include/c++/4.9/utility /usr/include/c++/4.9/bits/stl_relops.h \
 src/Game.h src/Color.h /usr/include/c++/4.9/iostream \
 /usr/include/c++/4.9/ostream /usr/include/c++/4.9/ios \
 /usr/include/c++/4.9/bits/ios_base.h \
 /usr/include/c++/4.9/bits/locale_classes.h \
 /usr/include/c++/4.9/bits/locale_classes.tcc \
 /usr/include/c++/4.9/streambuf /usr/include/c++/4.9/bits/streambuf.tcc \
 /usr/include/c++/4.9/bits/basic_ios.h \
 /usr/include/c++/4.9/bits/locale_facets.h /usr/include/c++/4.9/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/ctype_base.h \
 /usr/include/c++/4.9/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/bits/ctype_inline.h \
 /usr/include/c++/4.9/bits/locale_facets.tcc \
 /usr/include/c++/4.9/bits/basic_ios.tcc \
 /usr/include/c++/4.9/bits/ostream.tcc /usr/include/c++/4.9/istream \
 /usr/include/c++/4.9/bits/istream.tcc
