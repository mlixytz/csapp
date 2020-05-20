#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;
    struct stat buf;
    char *fp;

    if (argc != 2){
	printf("usage: %s <filename>\n", argv[0]);
	exit(0);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0) {
	printf("Error: cannot open file %s\n", argv[1]);
	exit(0);
    }
    if (fstat(fd, &buf) < 0) {
	printf("Error: cannot stat file %s\n", argv[1]);
        exit(0);
    }
    if((fp = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == NULL){
	printf("Error: mmap\n");
	exit(0);
    }
    write(1, fp, buf.st_size);
    exit(0);
}
