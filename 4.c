//writer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char* fifoFile = "myfifo";
    int fd;

    mkfifo(fifoFile, 0666);

    fd = open(fifoFile, O_WRONLY);
    if (fd == -1)
    {
        perror("Failed to open FIFO for writing");
        return 1;
    }

    char message[] = "Hello, reader!";
    write(fd, message, strlen(message) + 1);

    close(fd);
    return 0;
}

//reader
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char* fifoFile = "myfifo";
    int fd;
    char message[100];

    fd = open(fifoFile, O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open FIFO for reading");
        return 1;
    }

    read(fd, message, sizeof(message));
    printf("Received: %s\n", message);

    close(fd);
    return 0;
}
