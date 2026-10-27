#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char buffer[512];
    DIR *dir = opendir(".");
    if (dir == NULL) {
        const char *message = "Error opening directory\n";
        write(2, message, strlen(message));
        return 1;
    }

    int length = snprintf(buffer, sizeof(buffer), "%-30s %10s\n",
                          "Filename", "Size (bytes)");
    write(1, buffer, length);
    length = snprintf(buffer, sizeof(buffer), "%-30s %10s\n",
                      "------------------------------", "----------");
    write(1, buffer, length);

    struct dirent *entry;
    struct stat fileStat;
    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &fileStat) == 0) {
            length = snprintf(buffer, sizeof(buffer), "%-30s %10ld\n",
                              entry->d_name, (long)fileStat.st_size);
            write(1, buffer, length);
        }
    }

    closedir(dir);
    return 0;
}
