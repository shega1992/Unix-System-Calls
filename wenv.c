#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "wlib.h"

extern char ** environ;

int wsetenv(const char * name, const char * value, int overwrite)
{
     char * string;

     if(name == NULL || strlen(name) == 0 || strchr(name, '='))
     {
	  errno = EINVAL;
	  return -1;
     }
     
     if(getenv(name) && overwrite == 0)
	  return 0;
     else
     {	    
	  string = malloc(strlen(name) + strlen("=") + strlen(value) + 1);
	  if(string == NULL)
	  {
	       errno = ENOMEM;
	       return -1;
	  }

	  strcpy(string, name);
	  strcat(string, "=");
	  strcat(string, value);
   
	  if(putenv(string))	  
	       return -1;	  
	  else	       
	       return 0;	  
     }
}

int wunsetenv(const char * name)
{
     int i;

     if(name == NULL || strlen(name) == 0 || strchr(name, '='))
     {
	  errno = EINVAL;
	  return -1;
     }
     
     if(getenv(name) == NULL)
	  return 0;

     for(i = 0; strstr(environ[i], name) != environ[i]; i++)
	  ;

     do
     {
	  environ[i] = environ[i + 1];
     } while(environ[i++] != NULL);
     
     return 0;
}
     
	  
	  
