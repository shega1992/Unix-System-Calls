#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <wlib.h>

int main(void)
{
     int oldfd, newfd;
     const char * buf = "Test string";
     
     // oldfd is not a valid file descriptor
     oldfd = 4;
     newfd = wdup2(oldfd, 5);
     if(newfd == -1)
	  fprintf(stderr, "wdup2 : %s\n", strerror(errno));
     
     if((oldfd = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
     {
	  fprintf(stderr, "open : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }
     printf("oldfd = %d after open\n", oldfd);
	  
     // oldfd == newfd
     newfd = 3;
     newfd = wdup2(oldfd, newfd);
     printf("newfd = %d and oldfd = %d\n", newfd, oldfd);

     // newfd is not already open
     newfd = 4;
     newfd = wdup2(1, newfd);
     if(newfd == -1)
	  fprintf(stderr, "wdup2 : %s\n", strerror(errno));

     //Write to standard output using newfd
     if(write(newfd, buf, strlen(buf)) == -1)
     {
	  fprintf(stderr, "write : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     printf(" is printed using newfd\n");
     
     // Close oldfd
     oldfd = wdup2(1, oldfd); 
     if(oldfd == -1)
	  fprintf(stderr, "wdup2 : %s\n", strerror(errno));

     if(write(oldfd, buf, strlen(buf)) == -1)
     {
	  fprintf(stderr, "write : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     printf(" is printed using oldfd\n");

     return 0;
}

     
     
     
