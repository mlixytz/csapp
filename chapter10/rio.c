

#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd; // 读取的文件fd
    int rio_cnt; // 剩余未读字节数
    char *rio_bufptr; // 下一个未读字节的地址
    char rio_buf[RIO_BUFSIZE]; // 内部缓冲
} rio_t;


void rio_readinitb(rio_t *rp, int fd) {
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}

// 无缓冲的输入函数
ssize_t rio_readn(int fd, void *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
        if ((nread = read(fd, bufp, nleft)) < 0) {
            if (errno == EINTR)
                nread = 0;
            else
                return -1;
        } else if (nread == 0)
            break;
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft);
}

// 无缓冲的输出函数
ssize_t rio_writen(int fd, void *usrfbuf, size_t n) {
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;

    while (nleft > 0) {
        if ((nwrite = write(fd, bufp, nleft)) <= 0) {
            if (errno == EINTR)
                nwritten = 0;
            else
                return -1;
        }
        nleft -= nwritten;
        bufp += nwritten;
    }
    return n;
}

// linux read 缓冲版本
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
    int cnt;

    while (rp->rio_cnt <= 0) { // 当缓存为空时，重填
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
        if (rp->rio_cnt < 0) {
            if (errno != EINTR) {
                return -1;
            }
        }
        else if (rio->rio_cnt == 0) {
            return 0;
        }
        else {
            rp->rio_bufptr = rp->rio_buf;
        }
    }
    cnt = n;
    if (rp->cnt < n) {
        cnt = rp->cnt;
    }
    memcpy(usrbuf, rp->rio_bufptr, cnt);
    rp->rio_bufptr += cnt;
    rp->cnt -= cnt;
    return cnt;
}