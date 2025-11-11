#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int source, dest;
    char buffer[1024];
    ssize_t bytes;

    source = open("source.txt", O_RDONLY);
    dest = open("destination.txt", O_WRONLY | O_CREAT, 0644);

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
        write(dest, buffer, bytes);

    close(source);
    close(dest);

    printf("File copied successfully!\n");
    return 0;
}

