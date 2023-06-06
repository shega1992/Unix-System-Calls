#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wlib.h>

int main(void)
{
     char * result;
     result = wgetcwd(NULL, 0);
     if(result == NULL)
	  fprintf(stderr, "wgetcwd : %s\n", strerror(errno));
     else
	  puts(result);

     free(result);
}

