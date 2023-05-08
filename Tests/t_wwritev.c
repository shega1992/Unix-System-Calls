#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <wlib.h>

#define SIZE 4

struct entity
{
     char ch;
     int d;
     double f;
};

int main(void)
{
     int fd;
     struct w_buf buf[SIZE];

     struct entity en = {'a', 5, 7.5 };
     int x = 9;
     float y = 6.25;
     char c = 'b';
     ssize_t numWrite, totRequired;

     if((fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
     {
	  fprintf(stderr, "open : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     totRequired = 0;

     buf[0].w_base = &en;
     buf[0].w_len = sizeof(struct entity);
     totRequired += buf[0].w_len;
     buf[1].w_base = &x;
     buf[1].w_len = sizeof(x);
     totRequired += buf[1].w_len;
     buf[2].w_base = &y;
     buf[2].w_len = sizeof(y);
     totRequired += buf[2].w_len;
     buf[3].w_base = &c;
     buf[3].w_len = sizeof(c);
     totRequired += buf[3].w_len;

     if((numWrite = wwritev(fd, buf, SIZE)) == -1)
     {
	  fprintf(stderr, "wwritev : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     if(numWrite < totRequired)
	  printf("Write fewer bytes than requested\n");

     printf("total bytes requested: %ld; bytes write: %ld\n",
            (long) totRequired, (long) numWrite);

     return 0;
}
     

     
     
     
     

     
     
