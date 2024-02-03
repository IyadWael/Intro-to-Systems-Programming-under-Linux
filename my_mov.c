#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>



//int main(int argc, char** argv)
int main(int argc, char *argv[])
{

    int fd_1, fd_2, num_read, num_write;
    unsigned char buf[100];

    if (argc != 3) {
        printf("Usage: %s file_name\n", argv[0]);
        return -1;
    }

    fd_1 = open(argv[1], O_RDONLY);
    if (fd_1 < 0) {
        printf(">> Could not open the file\n");
        return -1;
    }
    printf(">> the file opend with fd = %d\n", fd_1);

    fd_2 = creat(argv[2], O_WRONLY);
    if (fd_2 < 0) {
        printf(">> Could not create the file\n");
        return -1;
    }

    while ((num_read = read(fd_1, buf, 100)) != 0) {
        if (num_read < 0) {
            printf(">> Could not read from the file\n");
            return -1;
        }
        printf(">> I read %d bytes\n", num_read);

        num_write = write(fd_2, buf, num_read);
        if (num_write < 0) {
            printf(">> Could not write to stdout\n");
            return -1;
        }
        printf("\n>> I wrote %d bytes\n", num_write);
    }


    unlink(argv[1]);

    close(fd_1);
    close(fd_2);

    return 0;
}

