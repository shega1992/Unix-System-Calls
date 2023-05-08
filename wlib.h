
struct w_buf
{
     void * w_base;
     size_t w_len;
};

int wdup(int oldfd);
int wdup2(int oldfd, int newfd);
ssize_t wreadv(int fd, const struct w_buf * v, int vcnt);
ssize_t wwritev(int fd, const struct w_buf * v, int vcnt);