# # list of gcc options (useful for finding what -I or -isystem mean)
# # 	Index:   https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Option-Index.html#Option-Index

# # Notes on make:
# 	# Comments outside of a 'target' aren't displayed
# 	# put @ symbol before a comment in a target to not display it when running

# 	# Define variables outside of targets and then reference them by $(NAME)
# 	# phony
# 	# define targets, recipes, dependencies
# 	# * expansion doesn't happen here like in dependencies, but will in a g++ command


# # # Source files
# # S_NAMES = AsciiView Board Dice Game utils
# # S_PATHS = $(addsuffix .cc, $(addprefix src/,$(S_NAMES)))
# # S_OBJS = $(addsuffix .o, $(S_NAMES))

# # Header files



# # Main
# ############################################################
# main: main.o objs
# 	echo $(S_OBJS)
# 	g++ $(S_OBJS) main.o -o $@

# # Objects
# ###################################################
# # $@ refers to the name of the target
# # $< refers to the first dependency of the target
# # 	No dependencies are mentioned here, but the dependencies are generated below
# #	It seems like the makefile yanks up the dependencies at the bottom of the file
# #	and puts them after the colon for these targets.  No problem with multiple
# #	definitions of the targets! At least when there's only one recipe (right here)

# # Take the SOURCES macro and replace all of the .cc with .o in the file names
CFLAGS = -std=c++11 -c
OBJDIR = build
SRCDIR = src
OBJS = $(addprefix $(OBJDIR)/,AsciiView.o Board.o Dice.o Game.o utils.o main.o)

# rule to make targets that look like build/*.o
# relying upon files like src/*.cc
# $@ refers to the target name (build/*.o) as the output file
# $< refers to the first prerequisite (src/*.o) as the g++ target
$(OBJDIR)/%.o : $(SRCDIR)/%.cc
	g++ $(CFLAGS) -o $@ $<

all: $(OBJS)

main: $(OBJS)
	g++ $(OBJS) -o $@


# objs: 

# AsciiView.o:
# 	g++ $(CFLAGS) $< -o $@
# Board.o: 
# 	g++ $(CFLAGS) $< -o $@
# Dice.o: 
# 	g++ $(CFLAGS) $< -o $@
# Game.o: 
# 	g++ $(CFLAGS) $< -o $@
# utils.o: 
# 	g++ $(CFLAGS) $< -o $@

# ##########
# main.o: main.cc $(OBJS)
# 	g++ $(CFLAGS) $< -o $@


# # Test
# ############################################################
# test: main_unittest

# T_NAMES = AsciiView_tests Board_tests Dice_tests Game_tests testmain
# T_PATHS = $(addsuffix .cc, $(addprefix tests/,$(T_NAMES)))
# T_OBJS = $(addsuffix .o, $(addprefix tests/,$(T_NAMES)))
# CFLAGS = -std=c++11 -c

# testobjs: $(T_OBJS)

# AsciiView_tests.o:
# 	g++ $(CFLAGS) $< -o $@
# Board_tests.o:
# 	g++ $(CFLAGS) $< -o $@
# Dice_tests.o:
# 	g++ $(CFLAGS) $< -o $@
# Game_tests.o:
# 	g++ $(CFLAGS) $< -o $@
# testmain.o:
# 	g++ $(CFLAGS) $< -o $@

# # Unit Tests
# ###########################################################
# INCLUDES = -isystem ${GTEST_DIR}/include -pthread
# main_unittest: libgtest.a objs
# 	g++ -std=c++11 $(INCLUDES) tests/* $(S_OBJS) libgtest.a \
# 	-o $@

# # Google Test static library file
# libgtest.a: gtest-all.o
# 	ar -rv libgtest.a gtest-all.o 

# # Google Test object file
# gtest-all.o: 
# 	g++ -isystem ${GTEST_DIR}/include -pthread -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc



# # Labels
# ##########################################################
# # This PHONY target lets 'make' know that it should always run these commands
# # even if there were a file named 'test' in the directory that was up to date.
# .PHONY: test clean depend objs

# Clean
##########################################################
clean:	
	rm -rf $(OBJDIR)/*


# Dependencies
########################################################
# Running "make depend" automatically generates dependencies for our object files
# it searches for the header files that a file depends on and lists them as dependencies
# it then appends those dependencies to the bottom of the file, right here!
depend:
	gccmakedep -- $(CFLAGS) -- src/*



# DO NOT DELETE
