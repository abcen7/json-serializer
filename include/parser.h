#pragma once
#include <stdbool.h>

typedef enum {
    JSON_NULL, JSON_BOOL, JSON_NUMBER,
    JSON_STRING, JSON_ARRAY, JSON_OBJECT
} JsonType;

typedef struct JsonValue JsonValue;

struct JsonValue {
    JsonType type;

    union {
        double number;
        bool boolean;
        char *string;

        struct {
            JsonValue **items;
            size_t count;
        } array;

        struct {
            char **keys;
            JsonValue **values;
            size_t count;
        } object;
    } u;
};
