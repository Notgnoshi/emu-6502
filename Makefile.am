AM_CFLAGS = \
	-g -O2 -std=c11 \
	-I$(srcdir)/include \
	-Wall -Wextra -Wpedantic \
	-Wshadow -Wstrict-overflow -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
	-Wformat=2 -Wno-unused-parameter -Wwrite-strings -Wstrict-prototypes -Wold-style-definition

lib_LTLIBRARIES = libemu.la
libemu_la_SOURCES = \
	src/add.c 	include/emu/add.h

bin_PROGRAMS = asm
asm_LDADD = libemu.la

check_PROGRAMS = tests/libemu
tests_libemu_LDADD = libemu.la

# Each $CASE.sh file is a test case for one of the project binaries. It is a script executed by the
# tests/runner.sh in the Makefile's CWD.
#
# The runner sets $EMU_REPO for use by the test scripts.
#
# By convention:
# * If $CASE.txt is present, it is the expected interleaved stdout/stderr of the program
# * If $CASE.hex is present, it is the expected assembler output, in Intel hex format
#
# NOTE: This test runner only works with the parallel test harness
TEST_EXTENSIONS = .sh
SH_LOG_COMPILER = $(srcdir)/tests/runner.sh

TESTS = \
	tests/libemu \
	tests/cases/test-version.sh
