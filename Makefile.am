lib_LTLIBRARIES = libemu.la
libemu_la_SOURCES = \
	src/add.c 	include/emu/add.h

AM_CFLAGS = -I$(srcdir)/include

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
