#include <unistd.h>
#include "wlib.h"

ssize_t wreadv(int fd, const struct w_buf * v, int vcnt)
{
     ssize_t numRead, totalRead = 0;
     // This is not atomic
     for(int i = 0; i < vcnt; i++)
     {
	  numRead = read(fd, v[i].w_base, v[i].w_len);
	  if(numRead == -1 || numRead == 0)
	       return numRead;
	  totalRead += numRead;
     }

     return totalRead;
}

ssize_t wwritev(int fd, const struct w_buf * v, int vcnt)
{
     ssize_t numWrite, totalWrite = 0;
     // This is not atomic
     for(int i = 0; i < vcnt; i++)
     {
	  numWrite = write(fd, v[i].w_base, v[i].w_len);
	  if(numWrite == -1)
	       return numWrite;
	  totalWrite += numWrite;
     }

     return totalWrite;
}
     
