### Tokenizer
**Goal:** read the input string and split her for ordered sequence of tokens for comfortable parsing.

### Parser
**Goal:** Based on the token sequence, construct a tree representation of JSON as a set of C-structures.

### Emitter
**Goal:** to bypass the resulting JsonValue* and form a correct JSON string (in compact or "pretty" form).

### Util
**Goal**: collect common helper-functions used by all modules