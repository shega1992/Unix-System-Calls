#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include "wlib.h"

char * wrealpath(const char * pathname, char * resolved_path)
{
     ssize_t numBytes;

     if(pathname == NULL)
     {
	  errno = EINVAL;
	  return NULL;
     }
     else if(resolved_path == NULL)
     {
	  resolved_path = malloc(PATH_MAX);
	  if(resolved_path == NULL)
	  {
	       errno = ENOMEM;
	       return NULL;
	  }
     }

     numBytes = readlink(pathname, resolved_path, PATH_MAX - 1);
     if(numBytes == -1)
	  return NULL;

     resolved_path[numBytes] = '\0';
     return resolved_path;
}

     

     
     

	  
	       
	  
