/* file_reader_sys.c */
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];
    ssize_t bytesRead;

    // 1. Open "output.txt" for reading
    int fd = open("output.txt", O_RDONLY);
    if (fd == -1) {
        write(2, "Error opening file\n", 19);   // 2 = stderr
        return 1;
    }

    // 2 + 3. Read chunks into buffer and write each chunk to the terminal
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        write(2, "Error reading file\n", 19);
    }

    // 4. Close the file
    close(fd);
    return 0;
}