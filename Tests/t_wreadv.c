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

     struct entity en;
     int x;
     float y;
     char c;
     ssize_t numRead, totRequired;

     if((fd = open("file.txt", O_RDONLY)) == -1)
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

     if((numRead = wreadv(fd, buf, SIZE)) == -1)
     {
	  fprintf(stderr, "wreadv : %s\n", strerror(errno));
	  exit(EXIT_FAILURE);
     }

     if(numRead < totRequired)
	  printf("Read fewer bytes than requested\n");

     printf("total bytes requested: %ld; bytes read: %ld\n",
            (long) totRequired, (long) numRead);

     printf("buf[0] contains: ch = %c, d = %d, f = %f\n", ((struct entity *)buf[0].w_base)->ch,
	    ((struct entity *)buf[0].w_base)->d,
	    ((struct entity *)buf[0].w_base)->f);
     printf("buf[1] constains: x = %d\n", *((int *) buf[1].w_base));
     printf("buf[2] contains: y = %f\n", *((float *) buf[2].w_base));
     printf("buf[3] contains: c = %c\n", *((char *) buf[3].w_base));
     
     return 0;
}
