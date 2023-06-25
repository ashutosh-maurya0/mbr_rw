PREFIX ?= /usr/local

CFLAGS := -I.

rd_b: rd_b.o
rd_b.o: rd_b.c

install:
	install -Dm0755 rd_b $(DESTDIR)$(PREFIX)/bin/rd_b

# Or if MacOS/POSIX
install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp rd_b $(DESTDIR)$(PREFIX)/bin
