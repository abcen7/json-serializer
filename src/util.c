#include "../include/util.h"
#include <stdlib.h>
#include <string.h>

void *xmalloc(const size_t size) {
    size_t real_size = (size > 0) ? size : 1;
    void *allocated = malloc(real_size);
    if (allocated == NULL) {
        fprintf(
            stderr,
            "Error: Insufficient memory (attempt to malloc %zu bytes)\n",
            size
        );

        exit(EXIT_FAILURE);
    }

    return allocated;
}

void *xcalloc(size_t n, size_t size) {
    void *allocated;

    n = (n > 0) ? n : 1;
    size = (size > 0) ? size : 1;
    allocated = calloc(n, size);
    if (allocated == NULL) {
        fprintf(
            stderr,
            "Error: Insufficient memory (attempt to calloc %zu bytes)\n",
            size
        );

        exit(EXIT_FAILURE);
    }

    return allocated;
}

void *xrealloc(void *p, size_t new_size) {
    void *allocated = realloc(p, new_size);
    if (allocated == NULL && new_size > 0) {
        fprintf(
            stderr,
            "Error: Insufficient memory (attempt to realloc %zu bytes)\n",
            new_size
        );

        exit(EXIT_FAILURE);
    }
}

char *xstrdup(const char *str) {
    char *p = malloc(strlen(str) + 1);

    if (p == NULL) {
        fprintf(stderr, "Error: Insufficient memory for xstrdup.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(p, str);

    return p;
}