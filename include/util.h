#pragma once
#include <stdio.h>

// Control dynamic buffer
void buffer_init(char **buffer, size_t *cap);

void buffer_append(char **buffer, size_t *length, size_t *capacity, const char *data, size_t n);

void buffer_free(char **buffer);

// Safety allocations
void *xmalloc(size_t size); // Exiting with error if getting NULL
void *xcalloc(size_t n, size_t size);
void *xrealloc(void *p, size_t new_size);

// String helpers
char *xstrdup(const char *str);

/*
 * Processes:
 * " -> \"
 * \ -> \\
 * \n, \t, etc.
 */
char *escape_json_string(const char *s);

// Common logics
void *array_grow(void *old_ptr, size_t *count, size_t elements_size);
