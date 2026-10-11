CC ?= cc
PREFIX ?= /usr/local

sw: sw.c
	$(CC) -Wall -Wextra -Werror sw.c -o sw

install: sw
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f sw $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/sw

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/sw

clean:
	rm -f sw

.PHONY: install uninstall clean
