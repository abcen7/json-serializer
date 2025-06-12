#pragma once
#include <stdbool.h>
#include <stdio.h>

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

/*
 * The main point of enter: initializes lexer, calls parse_value()
 * Checks that after value exactly TOK_EOF
 */
JsonValue *json_parse(const char *src, char **error_msg);

/*
 *  Branches execution depending on the current token:
 *  { → parse_object()
 *  [ → parse_array()
 *  TOK_STRING → creates string
 *  TOK_NUMBER → creates number
 *  TOK_TRUE / TOK_FALSE → creates bool
 *  TOK_NULL → creates NULL-value
 */
static JsonValue *parse_value(void);

// Reads pairs of "key": value until get }. Dynamically extends array keys/values
static JsonValue *parse_object(void);

// Reads elements until ], extends items array
static JsonValue *parse_array(void);

/*
 * When an unexpected token is detected,
 * generates a clear error message indicating the row/column.
 */
static void syntax_error(const char *msg);

// Recursively frees the memory for all nested structures
void json_value_free(JsonValue *value);
