SOURCES = wdup.c wreadv_wwritev.c wenv.c wgetpwnam.c wrealpath.c

all: wgetcwd.o
	gcc -shared -fPIC ${SOURCES} wgetcwd.o -o libwl.so

wgetcwd.o: wgetcwd.c wlib.h
	gcc -c wgetcwd.c -Wall -Werror -fno-stack-protector

clean:
	rm -f wgetcwd.o libwl.so
