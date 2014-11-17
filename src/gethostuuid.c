#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <uuid/uuid.h>

int main(int argc, char *argv[]) {
    struct timespec ts = { .tv_sec = 5, .tv_nsec = 0 };
    uuid_t uuid = {};

    if (gethostuuid(uuid, &ts) == -1) {
        switch (errno) {
        case EFAULT:
            fputs("Failed to get system UUID: unknown error", stderr);
            return 1;
        case EWOULDBLOCK:
            fputs("Failed to get system UUID: timeout expired", stderr);
            return 1;
        }
    }

    uuid_string_t uuid_string;
    uuid_unparse_upper(uuid, uuid_string);
    printf("%s\n", uuid_string);

    return 0;
}
