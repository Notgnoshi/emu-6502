lib_LTLIBRARIES = libemu.la
libemu_la_SOURCES = \
	src/add.c 	include/emu/add.h

AM_CFLAGS = -I$(srcdir)/include

bin_PROGRAMS = asm
asm_LDADD = libemu.la
