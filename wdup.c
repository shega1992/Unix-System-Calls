#include <unistd.h>
#include <fcntl.h>
#include "wlib.h"

int wdup(int oldfd)
{
     return fcntl(oldfd, F_DUPFD, 0);
}

int wdup2(int oldfd, int newfd)
{
     if(fcntl(oldfd, F_GETFL) == -1)
	  return -1;
     else if(oldfd == newfd)
	  return newfd;
     else if(fcntl(newfd, F_GETFL) == -1)
	  return fcntl(oldfd, F_DUPFD, newfd);
     else
     {	  // This is not atomic
	  close(newfd);
	  newfd = fcntl(oldfd, F_DUPFD, newfd);

	  return newfd;
     }
}
	  
