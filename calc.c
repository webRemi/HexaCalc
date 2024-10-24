#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t add(uint64_t first, uint64_t second);
uint64_t sub(uint64_t first, uint64_t second);
uint64_t calc(char *choice, uint64_t first, uint64_t second);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s 0xa3 + 0xbc\n", argv[0]);
        exit(1);
    }

    char *choice = argv[2];
    uint64_t first = strtoull(argv[1], NULL, 16);
    uint64_t second = strtoull(argv[3], NULL, 16);
    uint64_t result = calc(choice, first, second);

    printf("0x%" PRIx64 "\n", result);
    return 0;
}

uint64_t add(uint64_t first, uint64_t second) {
    return first + second;
}

uint64_t sub(uint64_t first, uint64_t second) {
    return first - second;
}

uint64_t calc(char *choice, uint64_t first, uint64_t second) {
    if (strcmp(choice, "+") == 0) {
        return add(first, second);
    } else if (strcmp(choice, "-") == 0) {
        return sub(first, second);
    } else {
        puts("Error: Invalid operator!");
        exit(1);
    }
}
