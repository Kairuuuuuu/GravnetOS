#ifndef FILE_MGT_H
#define FILE_MGT_H

#define MAX_FILES 3
#define MAX_NAME  16
#define MAX_DATA  128

struct FileEntry {
    char name[MAX_NAME];
    char data[MAX_DATA];
    int size;
};

void file_init(void);
int file_write(char *filename, char *text);
char *file_read(char *filename);

#endif