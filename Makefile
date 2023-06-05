SOURCES = wdup.c wreadv_wwritev.c wenv.c wgetpwnam.c wrealpath.c

all:
	gcc -shared -fPIC ${SOURCES} -o libwl.so

clean:
	rm -f libwl.so
