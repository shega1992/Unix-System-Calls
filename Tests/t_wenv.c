#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wlib.h>

extern char ** environ;

int main(void)
{
     char ** ep;
     wsetenv("TEST", "0xffff", 1);
     wsetenv("FALSE", "STATUS", 0);
     wsetenv("STATUS", "normal", 0);
     wsetenv("TRUE", "STATUS", 0);
     wsetenv("MY", "1", 1);
     wsetenv("YOUR", "2", -1);
     wsetenv("SHELL", "/home/wish", 1);
  
     for(ep = environ; *ep  != NULL; ep++)
	  puts(*ep);

     puts("----------------------------------------------");

     
     if(wunsetenv("STATUS") == -1)
     {
	  fprintf(stderr, "wunsetenv: %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     if(wunsetenv("YOUR") == -1)
     {
	  fprintf(stderr, "wunsetenv: %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     if(wunsetenv("MY") == -1)
     {
	  fprintf(stderr, "wunsetenv: %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     if(wunsetenv("STATUS") == -1)
     {
	  fprintf(stderr, "wunsetenv: %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     if(wunsetenv("SHELL") == -1)
     {
	  fprintf(stderr, "wunsetenv: %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     
     for(ep = environ; *ep  != NULL; ep++)
	  puts(*ep);

     return 0;
}
