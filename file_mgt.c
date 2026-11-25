#include "file_mgt.h"

struct FileEntry dir[MAX_FILES];

static int same_str(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

static int copy_str(char *dst, char *src, int limit) {
    int i = 0;
    while (src[i] != '\0' && i < limit - 1) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return i;
}

void file_init(void) {
    copy_str(dir[0].name, "file1.txt", MAX_NAME);
    dir[0].size = copy_str(dir[0].data, "Hello from GravNet OS", MAX_DATA);

    copy_str(dir[1].name, "file2.txt", MAX_NAME);
    dir[1].size = copy_str(dir[1].data, "", MAX_DATA);

    copy_str(dir[2].name, "notes.txt", MAX_NAME);
    dir[2].size = copy_str(dir[2].data, "CpE 3106 Operating Systems", MAX_DATA);
}

int file_write(char *filename, char *text) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (same_str(dir[i].name, filename)) {
            dir[i].size = copy_str(dir[i].data, text, MAX_DATA);
            return 1;
        }
    }
    return 0;
}

char *file_read(char *filename) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (same_str(dir[i].name, filename)) {
            return dir[i].data;
        }
    }
    return 0;
}