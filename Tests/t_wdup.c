#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <wlib.h>

int main(void)
{
     int newfd;

     newfd = wdup(1); // 3 is lowest unused file descriptor
     if(newfd == -1)
	  printf("wdup: %s\n", strerror(errno));
     
     // Write to standard output using newfd
     if(write(newfd, "test", 4) == -1)
     {
	  printf("write : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     printf("\nnewfd = %d\n", newfd);

     if(close(newfd) == -1)
     {
	  printf("close : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     // Close stderr
     if(close(2) == -1)
     {
	  printf("close : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     newfd = wdup(1); // 2 is lowest unused file descriptor
     if(newfd == -1)
	  printf("wdup: %s\n", strerror(errno));
     
     // Write to standard output using newfd
     if(write(newfd, "test2", 5) == -1)
     {
	  printf("write : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     printf("\nnewfd = %d\n", newfd);

     if(close(newfd) == -1)
     {
	  printf("close : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     newfd = wdup(3); // -1
     if(newfd == -1)
	  printf("wdup: %s\n", strerror(errno));

     return 0;
}

     
     
     
