typedef struct {
    char *buf;
    size_t len, cap;
    int indent;       // уровень отступа для pretty-print
    bool pretty;      // включить/выключить форматирование
} Emitter;
