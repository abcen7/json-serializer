#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "parser.h"

typedef struct {
    char *buf;
    size_t len, cap;
    short indent; // indentation-level for pretty-print
    bool pretty; // on/off pretty-formatter
} Emitter;

// Initializes Emitter calls emit_value(v), returns null-terminated string
char *json_serialize(JsonValue *v, bool pretty);

/*
 * Dispatcher. Depends of v->type calls:
 * emit_null(), emit_bool(), emit_number()
 * emit_string() (with shielding ", \, control characters)
 * emit_array(), emit_object()
 */
static void emit_value(Emitter *e, JsonValue *v);

// Creates open and close brackets: { }
static void emit_object(Emitter *e, JsonValue *v);

// Similarly for object, but without keys
static void emit_array(Emitter *e, JsonValue *v);

// Extends buffer if necessary and copies the string
static void append(Emitter *e, const char *s);

// Adds \n and the right amount of spaces bases on Emitter->indent
static void indent_newline(Emitter *e);