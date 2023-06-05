#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <wlib.h>

int main(int argc , char * argv[])
{
     char resolved_path[PATH_MAX];
     
     if(argc == 1)
     {
	  fprintf(stderr, "Usage: %s symlink\n", argv[0]);
	  exit(EXIT_FAILURE);
     }

     if(wrealpath(argv[1], resolved_path) == NULL)
     {
	  fprintf(stderr, "wrealpath: %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     else
	  puts(resolved_path);

     return 0;
}

     
