#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "wlib.h"

char * wgetcwd(char * buf, size_t size)
{
     DIR * dir;
     struct dirent * entry;
     struct stat cur, prev;
     static int level = 0;

     if(buf == NULL)
     {
	  if(size)
	       buf = malloc(size);
	  else
	       buf = malloc((size = PATH_MAX));

	  if(buf == NULL)
	  {
	       errno = ENOMEM;
	       return NULL;
	  }
     }

     if(stat(".", &cur) == -1)
	  return NULL;

     if(chdir("..") == -1)
	  return NULL;

     dir = opendir(".");
     if(dir == NULL)
	  return NULL;

     while((entry = readdir(dir)) != NULL)
     {
	  if(stat(entry->d_name, &prev) == -1)
	       return NULL;

	  if(cur.st_ino == prev.st_ino && cur.st_dev == prev.st_dev)
	       break;
     }

     if(entry == NULL)
	  return NULL;

     if(!strcmp(entry->d_name, "."))
	  return strcpy(buf, "/");
     else
     {
	  level++;
	  wgetcwd(buf, size);
	  level--;
	  if(strlen(buf) + 1 > size)
	  {
	       errno = ERANGE;
	       if(chdir(entry->d_name) == -1)
		    return NULL;

	       return NULL;
	  }
	       
	  strcat(buf, entry->d_name);
	  if(level != 0)
	       strcat(buf, "/");

	  if(chdir(entry->d_name) == -1)
	       return NULL;

	  return buf;
     }
}

     
	  
     
