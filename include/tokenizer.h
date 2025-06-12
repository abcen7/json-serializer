#pragma once
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    TOK_LBRACE, // {
    TOK_RBRACE, // }
    TOK_LBRACKET, // [
    TOK_RBRACKET, // ]
    TOK_COLON, // :
    TOK_COMMA, // ,
    TOK_STRING, // "…"
    TOK_NUMBER, // 123, -4.56, 1e10
    TOK_TRUE, // true
    TOK_FALSE, // false
    TOK_NULL, // null
    TOK_EOF, // end of input
    TOK_ERROR // lexer error
} TokenType;

typedef struct {
    TokenType type;
    char *lexeme; // not empty only for strings and numbers
    size_t line; // for error messages
    size_t column;
} Token;

// Initializes the internal buffer and position
void init_lexer(const char *src);

/* Skips the spaces and \n chars detects single symbols ({} [] : ,)
 * string literals, numbers (int and float types), keywords: true, false, null */
Token next_token(void);

// Frees the lexeme if it's not allocated
void free_token(Token *tok);

// Internal helpers
static void skip_whitespace(void);

static Token make_string(void);

static Token make_number(void);

static bool is_digit(char c);

static bool match(const char *kw);
