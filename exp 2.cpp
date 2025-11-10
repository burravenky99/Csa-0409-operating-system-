#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int sourceFile, destFile;
    char buffer[1024];
    ssize_t bytesRead, bytesWritten;

    
    sourceFile = open("source.txt", O_RDONLY);
    if (sourceFile == -1) {
        perror("Error opening source file");
        return 1;
    }

    
    destFile = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destFile == -1) {
        perror("Error opening destination file");
        close(sourceFile);
        return 1;
    }

   
    while ((bytesRead = read(sourceFile, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(destFile, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(sourceFile);
            close(destFile);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    }

    
    close(sourceFile);
    close(destFile);

    printf("File copied successfully.\n");

    return 0;
}

